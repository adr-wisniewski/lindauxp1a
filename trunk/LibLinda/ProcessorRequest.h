/* 
 * File:   ProcessorRequest.h
 * Author: adrian
 *
 * Created on 19 grudzień 2009, 20:32
 */

#ifndef _PROCESSORREQUEST_H
#define	_PROCESSORREQUEST_H

#include "RequestInput.h"
#include "RequestOutput.h"

namespace Linda
{
    /**
     * Request message processor interface
     */
    class ProcessorRequest
    {
    public:
        virtual void Process(RequestInput &r)   = 0;
        virtual void Process(RequestOutput &r)  = 0;
    };
}

#endif	/* _PROCESSORREQUEST_H */

