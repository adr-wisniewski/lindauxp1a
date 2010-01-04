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
    /**
     * Linda Read request for given query
     */
    class RequestRead : 
        public RequestInput,
        RegisterSerializable<RequestRead, MessageRequest>
    {
    public:
        RequestRead();
        RequestRead(const Query &query);

        virtual void Process(ProcessorRequest *processor);

    protected:
        virtual id_t Id() const;
    };
}

#endif	/* _REQUESTREAD_H */

