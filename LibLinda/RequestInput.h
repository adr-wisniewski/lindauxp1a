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
    class RequestInput;

    typedef MessageUnserializable<RequestInput, MessageRequest, 1>
            UnserializableRequestInput;

    class RequestInput : 
        public MessageRequest,
        private UnserializableRequestInput
    {
    public:
        RequestInput();
        RequestInput(const Query &query);

        virtual void DoSerialize(std::ostream &stream) const;
        virtual void DoUnserialize(std::istream &stream);

        virtual int GetCode() const;

        const Query& GivenQuery() const;
        void GivenQuery(const Query& value);

    protected:
        Query mGivenQuery;
    };
}

#endif	/* _REQUESTINPUT_H */

