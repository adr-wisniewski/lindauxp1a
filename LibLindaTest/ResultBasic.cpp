/* 
 * File:   ResultBasic.cpp
 * Author: adrian
 * 
 * Created on 19 grudzień 2009, 19:12
 */

#include "ResultBasic.h"
#include "ProcessorResult.h"
#include "Id.h"

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

    /*virtual*/ void ResultBasic::Process(ProcessorResult *processor)
    {
        processor->Process(*this);
    }

    /*virtual*/ id_t ResultBasic::Id() const
    {
        return ClassToId<ResultBasic>::Id();
    }
}
}





