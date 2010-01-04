/*
 * File:   CommandStat.cpp
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 13:18
 */

#include <string.h>
#include <list>

#include "CommandStat.h"
#include "ProcessorCommand.h"
#include "IdTest.h"

namespace Linda
{
namespace Test
{
    CommandStat::CommandStat()
    {

    }

    CommandStat::CommandStat(int ordinal)
    : MessageCommand(ordinal)
    {

    }

    /*virtual*/ void CommandStat::Process(ProcessorCommand *processor)
    {
        processor->Process(*this);
    }

    /*virtual*/ id_t CommandStat::Id() const
    {
        return ClassToId<CommandStat>::Id();
    }
}
}


