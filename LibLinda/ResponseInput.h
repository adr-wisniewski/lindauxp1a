/* 
 * File:   ResponseInput.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 19:02
 */

#ifndef _RESPONSEINPUT_H
#define	_RESPONSEINPUT_H

#include "MessageResponse.h"
#include "MessageUnserializable.h"

namespace Linda
{
    static const int ResponseInputCode = 1;

    class ResponseInput : 
        public MessageResponse,
        private MessageUnserializable<ResponseInput, MessageResponse, ResponseInputCode>
    {

    };
}

#endif	/* _RESPONSEINPUT_H */

