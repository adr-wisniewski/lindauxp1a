/* 
 * File:   ResultBasic.cpp
 * Author: adrian
 * 
 * Created on 19 grudzień 2009, 19:12
 */

#include "ResultBasic.h"
#include "ProcessorResult.h"
#include "IdTest.h"

namespace Linda
{
namespace Test
{
    ResultBasic::ResultBasic()
    {

    }

    ResultBasic::ResultBasic(int ordinal, StatusCode status)
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





