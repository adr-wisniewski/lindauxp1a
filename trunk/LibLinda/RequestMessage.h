/* 
 * File:   MessageRequest.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 17:03
 */

#ifndef _MESSAGEREQUEST_H
#define	_MESSAGEREQUEST_H

#include "Message.h"

namespace Linda
{
    struct Request_tag {};

    typedef Message<Request_tag> MessageRequest;

    typedef Pipe<MessageRequest> PipeRequest;
}

#endif	/* _MESSAGEREQUEST_H */

