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
    : mOrdinal(ordinal), mStatus(status)
    {

    }

    /*virtual*/ void MessageResult::DoSerialize(std::ostream &stream) const
    {
        stream << mOrdinal << mStatus;
    }

    /*virtual*/ void MessageResult::DoUnserialize(std::istream &stream)
    {
        stream >> mOrdinal >> mStatus;
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





