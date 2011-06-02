#include "MessageRequest.h"

namespace Linda
{
    MessageRequest::MessageRequest()
    {

    }

    MessageRequest::MessageRequest(pid_t pid)
    : mPid(pid)
    {

    }

    /*virtual*/ MessageRequest::~MessageRequest()
    {
    }

    /*virtual*/ void MessageRequest::DoSerialize(Archive &stream) const
    {
        stream << mPid;
    }

    /*virtual*/ void MessageRequest::DoUnserialize(Archive &stream)
    {
        stream >> mPid;
    }

    pid_t MessageRequest::Pid() const
    {
        return mPid;
    }

    void MessageRequest::Pid(pid_t value)
    {
        mPid = value;
    }
}


