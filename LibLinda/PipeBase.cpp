#include "PipeBase.h"
#include "Exception.h"
#include <cerrno>
#include <unistd.h>
#include <limits.h>
#include "Util.h"

namespace Linda
{
    /*static*/ const int PipeBase::EndClosed = 1;

    PipeBase::PipeBase()
    {
        if(pipe(mDescriptors) == -1)
            throw Exception(errno, "Linda::PipeBase - pipe call");
    }

    PipeBase::PipeBase(int readDescriptor, int writeDescriptor)
    {
        mDescriptors[EndRead]    = readDescriptor;
        mDescriptors[EndWrite]   = writeDescriptor;
    }

    PipeBase::~PipeBase()
    {
        CloseEnd(EndRead);
        CloseEnd(EndWrite);
    }

    int PipeBase::GetEnd(EndType which)
    {
        return mDescriptors[which];
    }

    int PipeBase::CloseEnd(EndType which)
    {
        if(mDescriptors[which] != EndClosed)
        {
            close(mDescriptors[which]);
            mDescriptors[which] = EndClosed;
        }
    }

    void PipeBase::Write(const void *buf, unsigned int length)
    {
        // check size
        if(length > PIPE_BUF)
            throw Exception(boost::format("Message too big: %1%B") % length);

        // co z błędami w szczegolnosci EINTR?
        if( write(mDescriptors[EndWrite], buf, length) == -1)
            throw Exception(errno, "Linda::PipeBase::Write - write call");
    }

    bool PipeBase::Read(void *buf, unsigned int length)
    {
        int result;
        int remaining = length;

        // read whole message
        do
        {
            // co z błędami w szczegolnosci EINTR?
            result = read(mDescriptors[EndRead], buf, length);

            // handle errors
            if(result == -1)
            {
                throw Exception(errno, "Linda::PipeBase::Read - read call");
            }
            // handle end of file
            else if(result == 0)
            {
                // if we didnt read anything its ok
                if(remaining == length)
                {
                    CloseEnd(EndRead);
                    return false;
                }
                // but this is incomplete read
                else
                {
                    throw Exception("Linda::PipeBase::Read: Incomplete read");
                }
            }

            remaining -= result;
        }
        while( remaining > 0);

        return true;
    }
}