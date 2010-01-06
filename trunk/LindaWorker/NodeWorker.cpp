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

namespace Linda
{
namespace Test
{

    NodeWorker::NodeWorker(int commandRead, int resultWrite, int requestWrite, int responseRead)
        :
        mLinda(responseRead, requestWrite),
        mPipeCommand(commandRead, PipeBase::EndClosed),
        mPipeResult(PipeBase::EndClosed, resultWrite)
    {

    }

    void NodeWorker::Run()
    {
        // read and process commands
        while(true)
        {
            boost::shared_ptr<MessageCommand> command(mPipeCommand.Read());

            // no more commands
            if(command == boost::shared_ptr<MessageCommand>())
                break;

            // process command
            command->Process(this);
        }
    }

    void NodeWorker::Process(CommandCreate &c)
    {
        throw Exception("Invalid command 'Create'");
    }

    void NodeWorker::Process(CommandKill &c)
    {
        throw Exception("Invalid command 'Kill'");
    }

    void NodeWorker::Process(CommandStat &c)
    {
        throw Exception("Invalid command 'Stat'");
    }

    void NodeWorker::Process(CommandOutput &c)
    {
        bool status = mLinda.Output(c.GivenTuple());
        mPipeResult.Write(ResultBasic(c.Ordinal(), status ? MessageResult::Status_Ok : MessageResult::Status_Fail));
    }

    void NodeWorker::Process(CommandInput &c)
    {
        Tuple tuple;

        bool status = mLinda.Input(c.GivenQuery(), tuple);
        mPipeResult.Write(ResultBasic(c.Ordinal(), status ? MessageResult::Status_Ok : MessageResult::Status_Fail));
    }

    void NodeWorker::Process(CommandRead &c)
    {
        Tuple tuple;

        bool status = mLinda.Read(c.GivenQuery(), tuple);
        mPipeResult.Write(ResultBasic(c.Ordinal(), status ? MessageResult::Status_Ok : MessageResult::Status_Fail));
    }

}
}

