#include "MessageResponse.h"

namespace Linda
{
    MessageResponse::MessageResponse()
    {

    }

    MessageResponse::MessageResponse(bool status)
    {
        Status(status);
    }

    /*virtual*/ void MessageResponse::DoSerialize(std::ostream &stream) const
    {
        stream << mStatus;
    }

    /*virtual*/ void MessageResponse::DoUnserialize(std::istream &stream)
    {
        stream >> mStatus;
    }

    bool MessageResponse::Status() const
    {
        return mStatus;
    }

    void MessageResponse::Status(bool value)
    {
        mStatus = value;
    }
}






