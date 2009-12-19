/*
 * File:   CommandKill.cpp
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 13:18
 */

#include <string.h>

#include "CommandKill.h"
#include "ProcessorCommand.h"

namespace Linda
{
namespace Test
{
    /*virtual*/ int CommandKill::GetCode() const
    {
        return UnserializableCommandKill::GetCode();
    }

    /*virtual*/ void CommandKill::Process(ProcessorCommand *processor)
    {
        processor->Process(*this);
    }
}
}


