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

    /*virtual*/ MessageResponse::~MessageResponse()
    {
    }

    /*virtual*/ void MessageResponse::DoSerialize(Archive &stream) const
    {
        stream << mStatus;
    }

    /*virtual*/ void MessageResponse::DoUnserialize(Archive &stream)
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






