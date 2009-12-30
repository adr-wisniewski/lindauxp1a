/* 
 * File:   Pipe.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 18:06
 */

#ifndef _PIPE_H
#define	_PIPE_H

#include "PipeBase.h"
#include <boost/shared_ptr.hpp>

namespace Linda
{

    template<class TProduct>
    class Pipe : public PipeBase
    {
    public:
        Pipe();
        Pipe(int readDescriptor, int writeDescriptor);

        void Write(const TProduct &p);
        boost::shared_ptr<TProduct> Read();
    };
}

#include "Pipe.impl.h"

#endif	/* _PIPE_H */

