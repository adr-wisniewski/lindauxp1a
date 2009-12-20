/* 
 * File:   ResultCreate.cpp
 * Author: adrian
 * 
 * Created on 20 grudzień 2009, 11:46
 */

#include "ResultCreate.h"
#include "ProcessorResult.h"
#include "Id.h"

namespace Linda
{
namespace Test
{

    ResultCreate::ResultCreate()
    {

    }

    ResultCreate::ResultCreate(int ordinal, bool status, pid_t pid)
    : MessageResult(ordinal, status), mPid(pid)
    {

    }

    /*virtual*/ void ResultCreate::DoSerialize(std::ostream &stream) const
    {
        MessageResult::DoSerialize(stream);
        stream << mPid;
    }

    /*virtual*/ void ResultCreate::DoUnserialize(std::istream &stream)
    {
        MessageResult::DoUnserialize(stream);
        stream >> mPid;
    }

    /*virtual*/ id_t ResultCreate::Id() const
    {
        return ClassToId<ResultCreate>::Id();
    }

    /*virtual*/ void ResultCreate::Process(ProcessorResult *processor)
    {
        processor->Process(*this);
    }

    pid_t ResultCreate::Pid() const
    {
        return mPid;
    }

    void ResultCreate::Pid(pid_t value)
    {
        mPid = value;
    }

}
}