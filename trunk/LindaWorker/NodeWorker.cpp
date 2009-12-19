/* 
 * File:   NodeWorker.cpp
 * Author: adrian
 * 
 * Created on 15 grudzień 2009, 15:28
 */

#include "NodeWorker.h"

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include <Tuple.h>
#include <Exception.h>

#include "PipeBase.h"
#include "ResultBasic.h"

NodeWorker::NodeWorker(int commandRead, int resultWrite, int requestWrite, int responseRead)
    :
    mLinda(responseRead, requestWrite),
    mPipeCommand(commandRead, Linda::PipeBase::EndClosed),
    mPipeResult(Linda::PipeBase::EndClosed, resultWrite)
{
    
}

void NodeWorker::Run()
{  
    // read and process commands
    while(true)
    {
        // should be boost::smart_ptr
        Linda::Test::MessageCommand *command = mPipeCommand.Read();

        // no more commands
        if(command == 0)
            break;

        // process command
        command->Process(this);

        // free command
        delete command; // should be boost::smart_ptr
    }
}

void NodeWorker::Process(Linda::Test::CommandCreate &c)
{
    throw Linda::Exception("Invalid command 'Create'");
}

void NodeWorker::Process(Linda::Test::CommandKill &c)
{
    throw Linda::Exception("Invalid command 'Kill'");
}

void NodeWorker::Process(Linda::Test::CommandStat &c)
{
    throw Linda::Exception("Invalid command 'Stat'");
}

void NodeWorker::Process(Linda::Test::CommandOutput &c)
{
    bool status = mLinda.Output(c.GivenTuple());
    mPipeResult.Write(Linda::Test::ResultBasic(c.Ordinal(), status));
}

void NodeWorker::Process(Linda::Test::CommandInput &c)
{
    Linda::Tuple tuple;

    bool status = mLinda.Input(c.GivenQuery(), tuple);
    mPipeResult.Write(Linda::Test::ResultBasic(c.Ordinal(), status));
}

void NodeWorker::Process(Linda::Test::CommandRead &c)
{
    Linda::Tuple tuple;

    bool status = mLinda.Read(c.GivenQuery(), tuple);
    mPipeResult.Write(Linda::Test::ResultBasic(c.Ordinal(), status));
}



