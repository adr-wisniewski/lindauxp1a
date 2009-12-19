#include "RequestRead.h"
#include "ProcessorRequest.h"

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

    /*virtual*/ void RequestRead::Process(ProcessorRequest *processor)
    {
        processor->Process(*this);
    }
}









