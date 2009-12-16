/* 
 * File:   ResultMessage.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 20:25
 */

#ifndef _RESULTMESSAGE_H
#define	_RESULTMESSAGE_H

#include <Message.h>

namespace Linda
{
    namespace Test
    {
        struct Result_tag
        {

        };

        typedef Message<Result_tag> ResultMessage;

        typedef Pipe<ResultMessage> ResultPipe;
    }
}

#endif	/* _RESULTMESSAGE_H */

