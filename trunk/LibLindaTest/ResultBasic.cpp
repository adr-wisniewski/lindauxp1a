/* 
 * File:   ResultBasic.cpp
 * Author: adrian
 * 
 * Created on 19 grudzień 2009, 19:12
 */

#include "ResultBasic.h"
#include "ProcessorResult.h"

namespace Linda
{
namespace Test
{
    ResultBasic::ResultBasic()
    {

    }

    ResultBasic::ResultBasic(int ordinal, bool status)
    : MessageResult(ordinal, status)
    {
    }

    /*virtual*/ int ResultBasic::GetCode() const
    {
        return UnserializableResultBasic::GetCode();
    }

    /*virtual*/ void ResultBasic::Process(ProcessorResult *processor)
    {
        processor->Process(*this);
    }
}
}





