/* 
 * File:   MessageRequestResult.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 17:03
 */

#ifndef _MESSAGERESPONSE_H
#define	_MESSAGERESPONSE_H

#include "Message.h"

namespace Linda
{
    class MessageResponse : public Message<MessageResponse>
    {

    };

    typedef Pipe<MessageResponse> PipeResponse;
}

#endif	/* _MESSAGERESPONSE_H */

