#include "CommandOutput.h"
#include "MessageResult.h"
#include "ProcessorResult.h"

namespace Linda
{
namespace Test
{
    MessageResult::MessageResult()
    {

    }

    MessageResult::MessageResult(int ordinal, bool status)
    {
        Ordinal(ordinal);
        Status(status);
    }

    /*virtual*/ void MessageResult::DoSerialize(std::ostream &stream)
    {
        stream << mOrdinal << mStatus;
    }

    /*virtual*/ Message* MessageResult::DoUnserialize(std::istream &stream)
    {
        stream >> mOrdinal >> mStatus;
    }

    /*virtual*/ int MessageResult::GetCode() const
    {
        return MessageUnserializableResult::GetCode();
    }

    /*virtual*/ void MessageResult::Process(ProcessorResult *processor)
    {
        processor->Process(*this);
    }

    int MessageResult::Ordinal() const
    {
        return mOrdinal;
    }

    void MessageResult::Ordinal(int value)
    {
        mOrdinal = value;
    }

    bool MessageResult::Status() const
    {
        return mStatus;
    }

    void MessageResult::Status(bool value)
    {
        mStatus = value;
    }
}
}





