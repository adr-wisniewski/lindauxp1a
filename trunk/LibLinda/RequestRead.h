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
    class RequestRead;

    typedef MessageUnserializable<RequestRead, MessageRequest, 3>
            UnserializableRequestRead;

    class RequestRead : 
        public RequestInput,
        private UnserializableRequestRead
    {
    public:
        RequestRead();
        RequestRead(const Query &query);

        virtual int GetCode() const;
    };
}

#endif	/* _REQUESTREAD_H */

