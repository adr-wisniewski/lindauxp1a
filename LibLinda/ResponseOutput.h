/* 
 * File:   ResponseOutput.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 19:03
 */

#ifndef _RESPONSEOUTPUT_H
#define	_RESPONSEOUTPUT_H

#include "MessageResponse.h"
#include "MessageUnserializable.h"

namespace Linda
{
    static const int ResponseOutputCode = 2;

    class ResponseOutput : 
        public MessageResponse,
        private MessageUnserializable<ResponseOutput, MessageResponse, ResponseOutputCode>
    {
        
    };
}

#endif	/* _RESPONSEOUTPUT_H */

