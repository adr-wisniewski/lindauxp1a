#include "StorageNode.h"
#include "Worker.h"

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

using namespace Linda;
using namespace Linda::Test;

StorageNode::StorageNode(int commandRead, int answerRead)
    :
    commandPipe(commandRead, Pipe::EndClosed),
    resultPipe(answerRead, Pipe::EndClosed)
{

}

int StorageNode::Run()
{
    fd_set rfd, afd;
    FD_ZERO(&afd);
    FD_SET(commandPipe.GetEnd(Pipe::ReadEnd), &afd);
    FD_SET(requestPipe.GetEnd(Pipe::ReadEnd), &afd);
    int max = commandPipe.GetEnd(Pipe::ReadEnd) > requestPipe.GetEnd(Pipe::ReadEnd) ? commandPipe.GetEnd(Pipe::ReadEnd), &afd) : requestPipe.GetEnd(Pipe::ReadEnd);
    while(true)
    {
        bcopy((char*)&afd, (char*)&rfd, sizeof(afd));
        if(select(max, &rfd, NULL, NULL, 0) < 0)
        {
            //throw Exception
        }
        if(FD_ISSET(requestPipe.GetEnd(Pipe::ReadEnd), &rfd))
        {

        }
        else
        {
            Linda::Test::MessageCommand *command = commandPipe.Read();
            /*
            if(command == 0)
            break;
            */
            command->Process(this);
            delete command;
        }
    }
}

void StorageNode::Process(Linda::Test::CommandCreate &c)
{
    try
    {
        Worker* worker = new Worker();
        workerList.push_back(worker);
        resultPipe.Write(c.Ordinal(), true, Linda::Test::ResultCreate(worker->GetId()));
    }
    catch(Linda::Exception &e)
    {
        resultPipe.Write(c.Ordinal(), false, Linda::Test::ResultCreate(worker->GetId()));
    }
    catch(Exception &e)
    {
        resultPipe.Write(c.Ordinal(), false, Linda::Test::ResultCreate(worker->GetId()));
        return EXIT_FAILURE;
    }
    
}

void StorageNode::Process(Linda::Test::CommandKill &c)
{
    RemoveWorker(c.Id());
    resultPipe.Write(Linda::Test::ResultKill(c.Ordinal(), true));
}

void StorageNode::Process(Linda::Test::CommandStat &c)
{
    resultPipe.Write(ResultStat(c.Ordinal(), true, tuplesList, waitingRequest));
}

void StorageNode::Process(Linda::Test::CommandOutput &c)
{
    Worker *w = FindWorker(c.Id());
    w->GetPipeCommand().Write(c);
}

void StorageNode::Process(Linda::Test::CommandInput &c)
{
    Worker *w = FindWorker(c.Id());
    w->GetPipeCommand().Write(c);
}

void StorageNode::Process(Linda::Test::CommandRead &c)
{
    Worker *w = FindWorker(c.Id());
    w->GetPipeCommand().Write(c);
}

void StorageNode::Process(Linda::RequestOutput &r)
{
    bool status = false;
    for(std::list<Waiting>::iterator i = waitingRequest.begin(), e = waitingRequest.end(); i != e;)
    {
        if((*i).query.IsSatisfied(r.GivenTuple()))
        {
            status = true;
            Worker* w = FindWorker((*i).id);
            w->GetPipeResponse().Write(Linda::ResponseOutput(true));
            i = waitingRequest.erase(i);
            if((*i).input)
                break;
        }
        else ++i;
    }
    if(!status)
        tuplesList.push_back(r.GivenTuple());
}

void StorageNode::Process(Linda::RequestInput &r)
{
    bool status = false;
    std::list<Linda::Tuple>::iterator i, e;
    for(i = tuplesList.begin(), e = tuplesList.end(); i != e; ++i)
        if(r.GivenQuery().IsSatisfied(*i))
            status = true;
    Worker* w = FindWorker(r.Id());
    if(status)
    {
        w->GetPipeResponse().Write(Linda::ResponseInput(true, (*i)));
        tuplesList.erase(i);
    }
    else
        waitingRequest.push_back(Waiting(w->GetId(), r.GivenQuery(), true));
}

void StorageNode::Process(Linda::RequestRead &r)
{
    bool status = false;
    std::list<Linda::Tuple>::iterator i, e;
    for(i = tuplesList.begin(), e = tuplesList.end(); i != e; ++i)
        if(r.GivenQuery().IsSatisfied(*i))
            status = true;
    Worker* w = FindWorker(r.Id());
    if(status)
        w->GetPipeResponse().Write(Linda::ResponseInput(true, (*i)));
    else
        waitingRequest.push_back(Waiting(w->GetId(), r.GivenQuery(), false));
}

void StorageNode::Remove(int id)
{
    for(std::list<Waiting>::iterator i = waitingRequest.begin(), e = waitingRequest.end(); i != e;)
        if((*i).id == id)
            i = waitingRequest.erase(i);
        else ++i;
}

void StorageNode::RemoveWorker(int id)
{
    for(std::list<Worker*>::iterator i = workerList.begin(), e = workerList.end(); i != e; ++i)
        if((*i)->GetId() == id)
        {
            Worker* w = *i;
            Remove(id);
            workerList.erase(i);
            delete w;
            return;
        }
    throw Linda::Exception("Process not exist");
}

Worker* StorageNode::FindWorker(int id)
{
    for(std::list<Worker*>::iterator i = workerList.begin(), e = workerList.end(); i != e; ++i)
        if((*i)->GetId() == id)
            return *i;
}