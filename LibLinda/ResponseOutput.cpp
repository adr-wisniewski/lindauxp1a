#include "ResponseOutput.h"
#include "ProcessorResponse.h"

namespace Linda
{
    ResponseOutput::ResponseOutput()
    {

    }

    ResponseOutput::ResponseOutput(bool status)
    : MessageResponse(status)
    {
    }

    /*virtual*/ int ResponseOutput::GetCode() const
    {
        return UnserializableResponseOutput::GetCode();
    }

    /*virtual*/ void ResponseOutput::Process(ProcessorResponse *processor)
    {
        processor->Process(*this);
    }
}








