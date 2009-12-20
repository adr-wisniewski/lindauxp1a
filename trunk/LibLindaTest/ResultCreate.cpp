/* 
 * File:   ResultCreate.cpp
 * Author: adrian
 * 
 * Created on 20 grudzień 2009, 11:46
 */

#include "ResultCreate.h"
#include "ProcessorResult.h"

namespace Linda
{
namespace Test
{

    ResultCreate::ResultCreate()
    {

    }

    ResultCreate::ResultCreate(int ordinal, bool status, int pid)
    : MessageResult(ordinal, status), mPid(pid)
    {

    }

    virtual void ResultCreate::DoSerialize(std::ostream &stream) const
    {
        MessageResult::DoSerialize(stream);
        stream << mPid;
    }

    virtual void ResultCreate::DoUnserialize(std::istream &stream)
    {
        MessageResult::DoUnserialize(stream);
        stream >> mPid;
    }

    virtual int ResultCreate::GetCode() const
    {
        return UnserializableResultCreate::GetCode();
    }

    virtual void ResultCreate::Process(ProcessorResult *processor)
    {
        processor->Process(*this);
    }

    int ResultCreate::Pid() const
    {
        return mPid;
    }

    void ResultCreate::Pid(int value)
    {
        mPid = value;
    }

}
}