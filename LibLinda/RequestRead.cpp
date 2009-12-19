#include "RequestRead.h"

namespace Linda
{
    RequestRead::RequestRead()
    {

    }

    RequestRead::RequestRead(const Query &query)
    : RequestInput(query)
    {
    }

    /*virtual*/ int RequestRead::GetCode() const
    {
        return UnserializableRequestRead::GetCode();
    }
}









