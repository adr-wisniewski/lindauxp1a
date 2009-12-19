/* 
 * File:   RequestOutput.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 17:07
 */

#ifndef _REQUESTOUTPUT_H
#define	_REQUESTOUTPUT_H

#include "MessageRequest.h"
#include "MessageUnserializable.h"
#include "Tuple.h"

namespace Linda
{
    static const int RequestOutputCode = 2;

    class RequestOutput : 
        public MessageRequest,
        private MessageUnserializable<RequestOutput, MessageRequest, RequestOutputCode>
    {

    protected:
        Tuple mTuple;
    };
}

#endif	/* _REQUESTOUTPUT_H */

