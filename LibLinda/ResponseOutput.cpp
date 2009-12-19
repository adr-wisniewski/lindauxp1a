#include "ResponseOutput.h"

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
}








