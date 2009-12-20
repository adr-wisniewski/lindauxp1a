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

    class MessageRequest : 
        public Message<ProcessorRequest>,
        public Serializable<MessageRequest>
    {

    };

    typedef Pipe<MessageRequest> PipeRequest;
}

#endif	/* _MESSAGEREQUEST_H */

