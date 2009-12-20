/* 
 * File:   MessageWorkerCommand.cpp
 * Author: adrian
 * 
 * Created on 20 grudzień 2009, 11:35
 */

#include "MessageWorkerCommand.h"

namespace Linda
{
namespace Test
{
    MessageWorkerCommand::MessageWorkerCommand()
    {

    }

    MessageWorkerCommand::MessageWorkerCommand(int ordinal, pid_t pid)
    : MessageCommand(ordinal), mPid(pid)
    {

    }

     /*virtual*/ void MessageWorkerCommand::DoSerialize(std::ostream &stream) const
    {
        MessageCommand::DoSerialize(stream);
        stream << mPid;
    }

    /*virtual*/ void MessageWorkerCommand::DoUnserialize(std::istream &stream)
    {
        MessageCommand::DoUnserialize(stream);
        stream >> mPid;
    }

    pid_t MessageWorkerCommand::Pid() const
    {
        return mPid;
    }

    void MessageWorkerCommand::Pid(pid_t value)
    {
        mPid = value;
    }
}
}