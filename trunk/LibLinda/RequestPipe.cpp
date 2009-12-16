#include "RequestPipe.h"

namespace Linda
{
    RequestPipe::RequestPipe() : Pipe()
    {

    }

    RequestPipe::RequestPipe(int readDescriptor, int writeDescriptor)
    : Pipe(readDescriptor, writeDescriptor)
    {

    }
}
