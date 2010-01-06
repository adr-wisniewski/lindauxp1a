/* 
 * File:   MessageRequest.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 17:03
 */

#ifndef _MESSAGEREQUEST_H
#define	_MESSAGEREQUEST_H


#include "Message.h"
#include "Serializable.h"
#include "Pipe.h"

namespace Linda
{
    class ProcessorRequest;

    /**
     * Base class for request messages
     */
    class MessageRequest : 
        public Message<ProcessorRequest>,
        public Serializable<MessageRequest>
    {
    public:
        MessageRequest();
        MessageRequest(pid_t pid);
        virtual ~MessageRequest();

        pid_t Pid() const;
        void Pid(pid_t value);

    protected:
        virtual void DoSerialize(Archive &stream) const;
        virtual void DoUnserialize(Archive &stream);

        pid_t mPid;
    };

    typedef Pipe<MessageRequest> PipeRequest;
}

#endif	/* _MESSAGEREQUEST_H */

