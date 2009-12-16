/* 
 * File:   RequestResultMessage.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 17:03
 */

#ifndef _REQUESTRESULTMESSAGE_H
#define	_REQUESTRESULTMESSAGE_H

#include "Message.h"

namespace Linda
{
    struct Response_tag
    {
        // empty tag structure
    };

    typedef Message<Response_tag> ResponseMessage;

    typedef Pipe<ResponseMessage> ResponsePipe;
}

#endif	/* _REQUESTRESULTMESSAGE_H */

