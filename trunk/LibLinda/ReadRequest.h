/* 
 * File:   ReadRequest.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 17:07
 */

#ifndef _READREQUEST_H
#define	_READREQUEST_H

#include "InputRequest.h"


namespace Linda
{
    static const int ReadRequestCode = 3;

    class ReadRequest : 
        public InputRequest,
        private UnserializableMessage<ReadRequest, RequestMessage, ReadRequestCode>
    {

    };
}

#endif	/* _READREQUEST_H */

