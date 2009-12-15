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

using namespace Linda;

WorkerNode::WorkerNode(int commandRead, int resultWrite, int requestWrite, int answerRead)
    :
    commandPipe(commandRead, Pipe::EndClosed),
    resultPipe(Pipe::EndClosed, resultWrite)
    requestPipe(Pipe::EndClosed, requestWrite)
    answerPipe(answerRead, Pipe::EndClosed)
{
    
}

int WorkerNode::Run()
{
    Command  *command;      // should be boost::smart_ptr

    // read and process commands
    while(true)
    {
        try
        {
            command = commandPipe.Read();
        }
        catch(Pipe::InvalidException &e)
        {
            printerror("Exception in worker " + getpid() + ": " + e.what());
            return (EXIT_FAILURE);
        }

        // no more commands
        if(command == 0)
            break;

        // execute command
        command->Execute(this);

        // free command
        delete command; // should be boost::smart_ptr
    }

    return (EXIT_SUCCESS);

}

void WorkerNode::Visit(Linda::Test::CommandCreate &c)
{
    printerror("Invalid command");
}

void WorkerNode::Visit(Linda::Test::CommandKill &c)
{
    printerror("Invalid command");
}

void WorkerNode::Visit(Linda::Test::CommandStat &c)
{
    printerror("Invalid command");
}

void WorkerNode::Visit(Linda::Test::CommandOutput &c)
{
    // execute command and write back results
    resultPipe.Write(command->execute());
}

void WorkerNode::Visit(Linda::Test::CommandInput &c)
{

}

void WorkerNode::Visit(Linda::Test::CommandRead &c)
{

}



