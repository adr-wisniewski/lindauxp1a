/* 
 * File:   RequestInput.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 17:06
 */

#ifndef _REQUESTINPUT_H
#define	_REQUESTINPUT_H

#include "MessageRequest.h"
#include "Query.h"

namespace Linda
{
    /**
     * Linda Input request for given query
     */
    class RequestInput : 
        public MessageRequest,
        RegisterSerializable<RequestInput, MessageRequest>
    {
    public:
        RequestInput();
        RequestInput(const Query &query);

        virtual void Process(ProcessorRequest *processor);

        const Query& GivenQuery() const;
        void GivenQuery(const Query& value);

    protected:
        virtual id_t Id() const;
        virtual void DoSerialize(std::ostream &stream) const;
        virtual void DoUnserialize(std::istream &stream);

        Query mGivenQuery;
    };
}

#endif	/* _REQUESTINPUT_H */

