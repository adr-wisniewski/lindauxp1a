/* 
 * File:   OutputRequest.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 17:07
 */

#ifndef _OUTPUTREQUEST_H
#define	_OUTPUTREQUEST_H

#include "RequestMessage.h"
#include "UnserializableMessage.h"
#include "Tuple.h"

namespace Linda
{
    static const int OutputRequestCode = 2;

    class OutputRequest : 
        public RequestMessage,
        private UnserializableMessage<OutputRequest, RequestMessage, OutputRequestCode>
    {

    protected:
        Tuple mTuple;
    };
}

#endif	/* _OUTPUTREQUEST_H */

