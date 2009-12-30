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

    MessageWorkerCommand::MessageWorkerCommand(int ordinal, int workerId)
    : MessageCommand(ordinal), mWorkerId(workerId)
    {

    }

     /*virtual*/ void MessageWorkerCommand::DoSerialize(std::ostream &stream) const
    {
        MessageCommand::DoSerialize(stream);
        stream << mWorkerId;
    }

    /*virtual*/ void MessageWorkerCommand::DoUnserialize(std::istream &stream)
    {
        MessageCommand::DoUnserialize(stream);
        stream >> mWorkerId;
    }

    int MessageWorkerCommand::WorkerId() const
    {
        return mWorkerId;
    }

    void MessageWorkerCommand::WorkerId(pid_t value)
    {
        mWorkerId = value;
    }
}
}