/*
 * File:   CommandKill.cpp
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 13:18
 */

#include <string.h>

#include "StatResult.h"

namespace Linda
{
namespace Test
{
    /*virtual*/ int StatResult::GetCode() const
    {
        return UnserializableStatResult::GetCode();
    }

    /*virtual*/ void StatResult::Process(ProcessorCommand *processor)
    {
        processor->Process(*this);
    }
}
}

