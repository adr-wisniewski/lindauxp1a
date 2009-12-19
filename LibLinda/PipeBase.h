/* 
 * File:   PipeBase.h
 * Author: adrian
 *
 * Created on 14 grudzień 2009, 22:10
 */

#ifndef _PIPEBASE_H
#define	_PIPEBASE_H



namespace Linda
{
    class PipeBase
    {
    public:
        PipeBase();
        PipeBase(int readDescriptor, int writeDescriptor);
        ~PipeBase();

        enum EndType
        {
            EndRead     = 0,
            EndWrite    = 1
        };

        int GetEnd(EndType which);
        int CloseEnd(EndType which);

        void Write(const void *buf, unsigned int length);
        bool Read(void *buf, unsigned int length);

        static const int EndClosed;

    protected:
        int mDescriptors[2];
    };

}

#endif	/* _PIPEBASE_H */

