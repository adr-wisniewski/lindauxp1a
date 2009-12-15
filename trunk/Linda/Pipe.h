/* 
 * File:   Pipe.h
 * Author: adrian
 *
 * Created on 14 grudzień 2009, 22:10
 */

#ifndef _PIPE_H
#define	_PIPE_H

namespace Linda
{
    class Pipe
    {
    public:
        Pipe();
        Pipe(int readDescriptor, int writeDescriptor);
        ~Pipe();

        enum EndType
        {
            EndRead     = 0,
            EndWrite    = 1
        };

        int GetEnd(EndType which);
        int CloseEnd(EndType which);

        void Write(void *buf, unsigned int length);
        bool Read(void *buf, unsigned int length);

        static const int EndClosed;

        class IncompleteRead : public std::runtime_error
        {
        public:
            IncompleteRead();
        };

    private:
        int mDescriptors[2];
    };

}

#endif	/* _PIPE_H */

