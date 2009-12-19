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
    class ResponseOutput;

    typedef MessageUnserializable<ResponseOutput, MessageResponse, 2>
            UnserializableResponseOutput;

    class ResponseOutput : 
        public MessageResponse,
        private UnserializableResponseOutput
    {
        ResponseOutput();
        ResponseOutput(bool status);

        virtual int GetCode() const;
    };
}

#endif	/* _RESPONSEOUTPUT_H */

