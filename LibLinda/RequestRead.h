/* 
 * File:   RequestRead.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 17:07
 */

#ifndef _REQUESTREAD_H
#define	_REQUESTREAD_H

#include "RequestInput.h"


namespace Linda
{
    static const int RequestReadCode = 3;

    class RequestRead : 
        public RequestInput,
        private MessageUnserializable<RequestRead, MessageRequest, RequestReadCode>
    {

    };
}

#endif	/* _REQUESTREAD_H */

