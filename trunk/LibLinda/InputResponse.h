/* 
 * File:   InputResponse.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 19:02
 */

#ifndef _INPUTRESPONSE_H
#define	_INPUTRESPONSE_H

#include "ResponseMessage.h"
#include "UnserializableMessage.h"

namespace Linda
{
    static const int InputResponseCode = 1;

    class InputResponse : 
        public ResponseMessage,
        private UnserializableMessage<InputResponse, ResponseMessage, InputResponseCode>
    {

    };
}

#endif	/* _INPUTRESPONSE_H */

