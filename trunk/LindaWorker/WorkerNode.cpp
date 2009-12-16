/* 
 * File:   WorkerNode.cpp
 * Author: adrian
 * 
 * Created on 15 grudzień 2009, 15:28
 */

#include "WorkerNode.h"

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <Exception.h>

#include <CommandMessage.h>

using namespace Linda;
using namespace Linda::Test;

WorkerNode::WorkerNode(int commandRead, int resultWrite, int requestWrite, int answerRead)
    :
    commandPipe(commandRead, Pipe::EndClosed),
    responsePipe(Pipe::EndClosed, resultWrite),
    requestPipe(Pipe::EndClosed, requestWrite),
    responsePipe(answerRead, Pipe::EndClosed)
{
    
}

int WorkerNode::Run()
{  
    // read and process commands
    while(true)
    {
        CommandMessage *command = commandPipe.Read(); // should be boost::smart_ptr

        // no more commands
        if(command == 0)
            break;

        // process command
        command->Process(this);

        // free command
        delete command; // should be boost::smart_ptr
    }
}

void WorkerNode::Process(Linda::Test::CreateCommand &c)
{
    throw Linda::Exception("Invalid command 'Create'");
}

void WorkerNode::Process(Linda::Test::KillCommand &c)
{
    throw Linda::Exception("Invalid command 'Kill'");
}

void WorkerNode::Process(Linda::Test::StatCommand &c)
{
    throw Linda::Exception("Invalid command 'Stat'");
}

void WorkerNode::Process(Linda::Test::OutputCommand &c)
{
    // TODO:
    // bool status = mLinda.Output(c.GetTuple());
    // resultPipe.Write(ResultMessage(c.GetOrdinal(), status));

    // execute command
    requestPipe.Write(OutputRequest(c.GetTuple()));

    // read response
    ResponseMessage* message = responsePipe.Read();

    // send back results
    resultPipe.Write(ResultMessage(c.GetOrdinal(), message->GetStatus()));

    // clean up
    delete message;
}

void WorkerNode::Process(Linda::Test::InputCommand &c)
{
    // TODO:
    // bool status = mLinda.Input(c.GetQuery(), tuple);
    // resultPipe.Write(InputResult(c.GetOrdinal(), status, tuple));

    // execute command
    requestPipe.Write(InputRequest(c.GetQuery()));

    // read results
    ResponseMessage* message = responsePipe.Read();

    // send back results
    resultPipe.Write(ResultMessage(c.GetOrdinal(), message->GetStatus()));

    // clean up
    delete message;
}

void WorkerNode::Process(Linda::Test::ReadCommand &c)
{
    // TODO:
    // bool status = mLinda.Read(c.GetQuery(), tuple);
    // resultPipe.Write(ResultMessage(c.GetOrdinal(), status, tuple));

    // execute command
    requestPipe.Write(ReadRequest(c.GetQuery()));

    // read results
    ResponseMessage* message = responsePipe.Read();

    // send back results
    resultPipe.Write(ResultMessage(c.GetOrdinal(), message->GetStatus()));

    // clean up
    delete message;
}



