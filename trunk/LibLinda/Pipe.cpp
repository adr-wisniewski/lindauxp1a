#include "Pipe.h"
#include "Exception.h"
#include <cerrno>
#include <unistd.h>

namespace Linda
{
    int Pipe::EndClosed = -1;

    Pipe::Pipe()
    {
        if(pipe(mDescriptors) == -1)
            throw Linda::Exception(errno, "pipe call in Linda::Pipe");
    }

    Pipe::Pipe(int readDescriptor, int writeDescriptor)
    {
        mDescriptors[EndRead]    = readDescriptor;
        mDescriptors[EndWrite]   = writeDescriptor;
    }

    Pipe::~Pipe()
    {
        CloseEnd(EndRead);
        CloseEnd(EndWrite);
    }

    int Pipe::GetEnd(EndType which)
    {
        return mDescriptors[which];
    }

    int Pipe::CloseEnd(EndType which)
    {
        if(mDescriptors[which] != EndClosed)
        {
            close(mDescriptors[which]);
            mDescriptors[which] = EndClosed;
        }
    }

    void Pipe::Write(void *buf, unsigned int length)
    {
        // co z błędami w szczegolnosci EINTR?
        if( write(mDescriptors[EndWrite], buf, length) == -1)
            throw Linda::Exception(errno, "write in Pipe::Write");
    }

    void Pipe::Read(void *buf, unsigned int length)
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
                throw Linda::Exception(errno, "read in Pipe::Read");
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
                    throw Pipe::IncompleteRead();
                }
            }

            remaining -= result;
        }
        while( remaining > 0);

        return true;
    }

    Pipe::IncompleteRead::IncompleteRead()
        : std::runtime_error("Incomplete read")
    {

    }
}