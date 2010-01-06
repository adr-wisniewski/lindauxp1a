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
        RequestInput(pid_t pid, bool isRemoving, const Query &query);

        virtual void Process(ProcessorRequest *processor);

        const Query& GivenQuery() const;
        void GivenQuery(const Query& value);

        bool IsRemoving() const;
        void IsRemoving(bool value);

    protected:
        virtual id_t Id() const;
        virtual void DoSerialize(Archive &stream) const;
        virtual void DoUnserialize(Archive &stream);

        bool mIsRemoving;
        Query mGivenQuery;
    };
}

#endif	/* _REQUESTINPUT_H */

