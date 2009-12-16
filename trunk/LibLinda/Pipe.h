/* 
 * File:   Pipe.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 18:06
 */

#ifndef _PIPE_H
#define	_PIPE_H

#include "PipeBase.h"

namespace Linda
{
    template<TProduct>
    class Pipe : public PipeBase
    {
        Pipe();
        Pipe(int readDescriptor, int writeDescriptor);

        void Write(const TProduct &p);
        TProduct* Read();
    };
}

#include "Pipe_impl.h"

#endif	/* _PIPE_H */

