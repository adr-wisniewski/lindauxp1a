/* 
 * File:   ProcessorResponse.h
 * Author: adrian
 *
 * Created on 19 grudzień 2009, 21:12
 */

#ifndef _PROCESSORRESPONSE_H
#define	_PROCESSORRESPONSE_H

#include "ResponseInput.h"
#include "ResponseOutput.h"

namespace Linda
{
    /**
     * Response message processor interface
     */
    class ProcessorResponse
    {
    public:
        virtual void Process(ResponseInput &r)    = 0;
        virtual void Process(ResponseOutput &r)   = 0;
    };
}

#endif	/* _PROCESSORRESPONSE_H */

