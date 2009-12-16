/* 
 * File:   RequestPipe.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 17:28
 */

#ifndef _REQUESTPIPE_H
#define	_REQUESTPIPE_H

#include "Pipe.h"

namespace Linda
{
    class RequestPipe : public Pipe
    {
    public:
        RequestPipe();
        RequestPipe(int readDescriptor, int writeDescriptor);
    };
}

#endif	/* _REQUESTPIPE_H */

