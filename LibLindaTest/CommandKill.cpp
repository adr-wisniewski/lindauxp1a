/*
 * File:   CommandKill.cpp
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 13:18
 */

#include "CommandKill.h"
#include "ProcessorCommand.h"
#include "Id.h"

namespace Linda
{
namespace Test
{
    CommandKill::CommandKill()
    {

    }

    CommandKill::CommandKill(int ordinal, pid_t pid)
    : MessageWorkerCommand(ordinal, pid)
    {
        
    }

    /*virtual*/ void CommandKill::Process(ProcessorCommand *processor)
    {
        processor->Process(*this);
    }

    /*virtual*/ id_t CommandKill::Id() const
    {
        return ClassToId<CommandKill>::Id();
    }
}
}


