#include "MessageResult.h"
#include "ProcessorResult.h"
#include <Exception.h>
#include <boost/format.hpp>

namespace Linda
{
namespace Test
{
    MessageResult::MessageResult()
    {

    }

    MessageResult::MessageResult(int ordinal, StatusCode status)
    : mOrdinal(ordinal), mStatus(status)
    {

    }

    /*virtual*/ void MessageResult::DoSerialize(std::ostream &stream) const
    {
        stream << mOrdinal << static_cast<int>(mStatus);
    }

    /*virtual*/ void MessageResult::DoUnserialize(std::istream &stream)
    {
        int status;

        stream >> mOrdinal;
        stream >> status;
        
        if(status < Status_MinCode || status > Status_MaxCode)
            throw Exception(boost::format("MessageResult::DoUnserialize: Unknown status code %1%") % status);

        mStatus = static_cast<StatusCode>(status);
    }

    int MessageResult::Ordinal() const
    {
        return mOrdinal;
    }

    void MessageResult::Ordinal(int value)
    {
        mOrdinal = value;
    }

    MessageResult::StatusCode MessageResult::Status() const
    {
        return mStatus;
    }

    void MessageResult::Status(StatusCode value)
    {
        mStatus = value;
    }
}
}





