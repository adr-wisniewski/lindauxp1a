/*
 * File:   CommandStat.cpp
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 13:18
 */

#include <string.h>
#include <list>

#include "CommandStat.h"

namespace Linda
{
namespace Test
{
    /*virtual*/ void CommandStat::DoSerialize(std::ostream &stream)
    {
        MessageCommand::DoSerialize(stream);
    }

    /*virtual*/ Message* CommandStat::DoUnserialize(std::istream &stream)
    {
        MessageCommand::DoUnserialize(stream);
    }

    /*virtual*/ int CommandStat::GetCode() const
    {
        return UnserializableCommandStat::GetCode();
    }

    /*virtual*/ void CommandStat::Process(ProcessorCommand *processor)
    {
        processor->Process(*this);
    }
}
}


