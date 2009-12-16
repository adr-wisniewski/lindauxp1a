/* 
 * File:   InputRequest.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 17:06
 */

#ifndef _INPUTREQUEST_H
#define	_INPUTREQUEST_H

#include "RequestMessage.h"
#include "UnserializableMessage.h"
#include "Query.h"

namespace Linda
{
    static const int InputRequestCode = 1;

    class InputRequest : 
        public RequestMessage,
        private UnserializableMessage<InputRequest, RequestMessage, InputRequestCode>
    {
    protected:
        Query mQuery;
    };
}

#endif	/* _INPUTREQUEST_H */

