/* 
 * File:   MessageRequestResult.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 17:03
 */

#ifndef _MESSAGERESPONSE_H
#define	_MESSAGERESPONSE_H

#include "Message.h"
#include "Serializable.h"
#include "Pipe.h"

namespace Linda
{
    class ProcessorResponse;

    class MessageResponse :
        public Serializable<MessageResponse>,
        public Message<ProcessorResponse>
    {
    public:
        MessageResponse();
        MessageResponse(bool status);

        bool Status() const;
        void Status(bool value);

    protected:
        virtual void DoSerialize(std::ostream &stream) const;
        virtual void DoUnserialize(std::istream &stream);

        bool mStatus;
    };

    typedef Pipe<MessageResponse> PipeResponse;
}

#endif	/* _MESSAGERESPONSE_H */

