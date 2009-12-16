/* 
 * File:   OutputResponse.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 19:03
 */

#ifndef _OUTPUTRESPONSE_H
#define	_OUTPUTRESPONSE_H

#include "ResponseMessage.h"
#include "UnserializableMessage.h"

namespace Linda
{
    static const int OutputResponseCode = 2;

    class OutputResponse : 
        public ResponseMessage,
        private UnserializableMessage<OutputResponse, ResponseMessage, OutputResponseCode>
    {
        
    };
}

#endif	/* _OUTPUTRESPONSE_H */

