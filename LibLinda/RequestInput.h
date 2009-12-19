/* 
 * File:   RequestInput.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 17:06
 */

#ifndef _REQUESTINPUT_H
#define	_REQUESTINPUT_H

#include "MessageRequest.h"
#include "MessageUnserializable.h"
#include "Query.h"

namespace Linda
{
    static const int RequestInputCode = 1;

    class RequestInput : 
        public MessageRequest,
        private MessageUnserializable<RequestInput, MessageRequest, RequestInputCode>
    {
    protected:
        Query mQuery;
    };
}

#endif	/* _REQUESTINPUT_H */

