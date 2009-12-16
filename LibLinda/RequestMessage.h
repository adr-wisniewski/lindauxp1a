/* 
 * File:   RequestMessage.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 17:03
 */

#ifndef _REQUESTMESSAGE_H
#define	_REQUESTMESSAGE_H

#include "Message.h"

namespace Linda
{
    struct Request_tag
    {
        // empty tag structure
    };

    typedef Message<Request_tag> RequestMessage;

    typedef Pipe<RequestMessage> RequestPipe;
}

#endif	/* _REQUESTMESSAGE_H */

