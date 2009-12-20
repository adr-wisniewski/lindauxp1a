#include "ResponseOutput.h"
#include "ProcessorResponse.h"
#include "Id.h"

namespace Linda
{
    ResponseOutput::ResponseOutput()
    {

    }

    ResponseOutput::ResponseOutput(bool status)
    : MessageResponse(status)
    {
    }

    /*virtual*/ void ResponseOutput::Process(ProcessorResponse *processor)
    {
        processor->Process(*this);
    }

    /*virtual*/ id_t ResponseOutput::Id() const
    {
        return ClassToId<ResponseOutput>::Id();
    }
}








