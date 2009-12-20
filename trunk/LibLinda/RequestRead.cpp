#include "RequestRead.h"
#include "ProcessorRequest.h"
#include "Id.h"

namespace Linda
{
    RequestRead::RequestRead()
    {

    }

    RequestRead::RequestRead(const Query &query)
    : RequestInput(query)
    {
    }

    /*virtual*/ void RequestRead::Process(ProcessorRequest *processor)
    {
        processor->Process(*this);
    }

    /*virtual*/ id_t RequestRead::Id() const
    {
        return ClassToId<RequestRead>::Id();
    }
}









