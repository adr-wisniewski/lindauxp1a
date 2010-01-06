#include "StorageNode.h"

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>
#include <cerrno>
#include <boost/lexical_cast.hpp>

#include <Exception.h>
#include <ResultBasic.h>
#include <ResultStat.h>
#include <ResponseInput.h>
#include <ResponseOutput.h>
#include <Util.h>

namespace Linda
{
namespace Test
{


StorageNode::StorageNode(int commandRead, int resultWrite)
    :
    mChildCount(0),
    mStatus(true),
    commandPipe(commandRead, PipeBase::EndClosed),
    resultPipe(PipeBase::EndClosed, resultWrite)
{

}


bool StorageNode::Run()
{
    int command = commandPipe.GetEnd(PipeBase::EndRead);
    int request = requestPipe.GetEnd(PipeBase::EndRead);

    // flags for each source;
    bool isCommandOpened = true;

    // read
    do
    {
        // initialize
        fd_set set;
        FD_ZERO (&set);

        struct timeval tv;
        tv.tv_sec = 0;
        tv.tv_usec = 200000;

        if(isCommandOpened)
            FD_SET(command, &set);

        FD_SET(request, &set);

        // pick descriptor
        int selectValue = TEMP_FAILURE_RETRY(select(FD_SETSIZE, &set, NULL, NULL, &tv));

        if( selectValue == -1)
            throw Linda::Exception(errno, "StorageNode::Run select");

        if( selectValue != 0 )
        {
            // process command
            if(isCommandOpened && FD_ISSET(command, &set))
            {
                isCommandOpened = ProcessCommand();
            }

            // process request
            if(FD_ISSET(request, &set))
                ProcessRequest();
        }
        else
        {
            while(mChildCount > 0)
            {
                int status;
                int ret = wait3(&status, WNOHANG, 0);

                if(ret == -1)
                    throw Linda::Exception(errno, "StorageNode::Run wait3");

                if(ret == 0)
                    break;
                
                --mChildCount;
                Linda::debug_print(boost::str(
                    boost::format("Storage: collected child - %1% left\n") % mChildCount
                ));

                if(!WIFEXITED(status) || WEXITSTATUS(status) != EXIT_SUCCESS)
                    mStatus = false;
            }
        }
    }
    while(isCommandOpened || mChildCount > 0);

    //Linda::debug_print(std::string("Storage: exitting...\n"));
    return mStatus;
}

bool StorageNode::ProcessCommand()
{
    boost::shared_ptr<MessageCommand> command(commandPipe.Read());

    if(command == boost::shared_ptr<MessageCommand>())
    {
        //Linda::debug_print(std::string("Storage: closing command pipe\n"));
        commandPipe.CloseEnd(PipeBase::EndRead);
        return false;
    }

    command->Process(this);
    return true;
}

bool StorageNode::ProcessRequest()
{
    boost::shared_ptr<MessageRequest> request(requestPipe.Read());

    if(request == boost::shared_ptr<MessageRequest>())
        return false;

    request->Process(this);
    return true;
}

void StorageNode::Process(CommandCreate &c)
{
    // create new worker entry
    boost::shared_ptr<Worker> worker(new Worker());
    worker->active = true;
    worker->workerId = c.WorkerId();

    // check if id already exists
    if(GetWorkerByWorkerId(worker->workerId) != workerList.end())
    {
        resultPipe.Write(ResultBasic(c.Ordinal(), MessageResult::Status_WorkerAlreadyExists));
        return;
    }

    // create process
    switch(worker->workerPid = fork())
    {
        // error
        case -1:
            throw Exception(errno, "StorageNode::Process(CommandCreate) fork");

        // child - close write end for created pipes
        case 0:
        {
            worker->commandPipe.CloseEnd(PipeBase::EndWrite);
            worker->responsePipe.CloseEnd(PipeBase::EndWrite);

            // execute worker program
            std::string commandRead =
                boost::lexical_cast<std::string>(worker->commandPipe.GetEnd(PipeBase::EndRead));

            std::string resultWrite =
                boost::lexical_cast<std::string>(resultPipe.GetEnd(PipeBase::EndWrite));

            std::string requestWrite =
                boost::lexical_cast<std::string>(requestPipe.GetEnd(PipeBase::EndWrite));

            std::string responseRead =
                boost::lexical_cast<std::string>(worker->responsePipe.GetEnd(PipeBase::EndRead));

            execlp("lindaworker",
                    "lindaworker",
                    commandRead.c_str(),
                    resultWrite.c_str(),
                    requestWrite.c_str(),
                    responseRead.c_str(),
                    (char*)0);


            // should not enter here
            throw Exception(errno, "StorageNode::Process(CommandCreate) execlp");
        }

        // parent - close reading ends for ceated pipes
        default:
            ++mChildCount;
            worker->commandPipe.CloseEnd(PipeBase::EndRead);
            worker->responsePipe.CloseEnd(PipeBase::EndRead);
    }

    // add worker to list and send acknowledge
    workerList.push_back(worker);
    resultPipe.Write(ResultBasic(c.Ordinal(), MessageResult::Status_Ok));
}

void StorageNode::Process(CommandKill &c)
{
    int workerId = c.WorkerId();
    WorkerList::iterator worker = GetWorkerByWorkerId(workerId);

    // didnt find
    if(worker == workerList.end())
    {
        resultPipe.Write(ResultBasic(c.Ordinal(), MessageResult::Status_WorkerDoesntExists));
        return;
    }
    else if(!(*worker)->active)
    {
        resultPipe.Write(ResultBasic(c.Ordinal(), MessageResult::Status_WorkerKilled));
        return;
    }

    // deactivate worker and close his command pipe
    (*worker)->active = false;
    (*worker)->commandPipe.CloseEnd(PipeBase::EndWrite);

    // send acknowledge
    resultPipe.Write(ResultBasic(c.Ordinal(), MessageResult::Status_Ok));
    return;
}

void StorageNode::Process(CommandStat &c)
{
    resultPipe.Write(ResultStat(c.Ordinal(), tuplesList, waitingRequest));
}

void StorageNode::Process(CommandOutput &c)
{
    RelayCommand(c);
}

void StorageNode::Process(CommandInput &c)
{
    RelayCommand(c);
}

void StorageNode::Process(CommandRead &c)
{
    RelayCommand(c);
}

void StorageNode::Process(RequestOutput &r)
{
    // acknowledge request
    WorkerList::iterator recipent = GetWorkerByWorkerPid(r.Pid());

    if(recipent == workerList.end())
        throw Exception(boost::format("Unknown request recipent %1%") % r.Pid());

    (*recipent)->responsePipe.Write(ResponseOutput(true));

    // check awaiting reads first
    for(ReadList::iterator i = waitingRequest.begin(), e = waitingRequest.end(); i != e;)
    {
        AwaitingRead &read = *i;

        if(read.query.IsSatisfied(r.GivenTuple()))
        {
            // send it to awaiting process
            (*GetWorkerByWorkerId(read.workerId))->responsePipe.Write(ResponseInput(true,r.GivenTuple()));

            bool exit = read.isRemoving;

            // remove this entry
            i = waitingRequest.erase(i);

            // end if read was removing
            if(exit)
                return;
        }
        else 
        {
            ++i;
        }
    }

    // tuple wasnt consumed
    tuplesList.push_back(r.GivenTuple());
}

void StorageNode::Process(RequestInput &r)
{
    // browse storage
    for(TupleList::iterator i = tuplesList.begin(), e = tuplesList.end(); i != e; ++i)
    {
        Tuple &tuple = *i;

        // found match
        if(r.GivenQuery().IsSatisfied(tuple))
        {
            // return result
            WorkerList::iterator recipent = GetWorkerByWorkerPid(r.Pid());

            if(recipent == workerList.end())
                throw Exception(boost::format("Unknown request recipent %1%") % r.Pid());

            (*recipent)->responsePipe.Write(ResponseInput(true, tuple));

            // if its removing read, remove tuple from storage
            if(r.IsRemoving())
                tuplesList.erase(i);

            return;
        }
    }

    // curretly nothing matches - add to awaiting reads
    WorkerList::iterator awaiting = GetWorkerByWorkerPid(r.Pid());

    if(awaiting == workerList.end())
        throw Exception(boost::format("Unknown request recipent %1%") % r.Pid());

    AwaitingRead read;
    read.isRemoving = r.IsRemoving();
    read.workerId = (*awaiting)->workerId;
    read.query = r.GivenQuery();

    waitingRequest.push_back(read);
}

StorageNode::WorkerList::iterator StorageNode::GetWorkerByWorkerId(int workerId)
{
    for(WorkerList::iterator i = workerList.begin(), e = workerList.end(); i != e; ++i)
    {
        if((*i)->workerId == workerId)
            return i;
    }
            
    return workerList.end();
}

StorageNode::WorkerList::iterator StorageNode::GetWorkerByWorkerPid(pid_t workerPid)
{
    for(WorkerList::iterator i = workerList.begin(), e = workerList.end(); i != e; ++i)
    {
        if((*i)->workerPid == workerPid)
            return i;
    }

    return workerList.end();
}

void StorageNode::RelayCommand(MessageWorkerCommand &c)
{
    int workerId = c.WorkerId();
    WorkerList::iterator worker = GetWorkerByWorkerId(workerId);

    // check if worker exists
    if(worker == workerList.end())
    {
        resultPipe.Write(ResultBasic(c.Ordinal(), MessageResult::Status_WorkerDoesntExists));
    }
    else if(!(*worker)->active)
    {
        resultPipe.Write(ResultBasic(c.Ordinal(), MessageResult::Status_WorkerKilled));
    }
    else
    {
        (*worker)->commandPipe.Write(c);
    }
}

}
}