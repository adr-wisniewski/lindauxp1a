/* 
 * File:   ResponseOutput.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 19:03
 */

#ifndef _RESPONSEOUTPUT_H
#define	_RESPONSEOUTPUT_H

#include "MessageResponse.h"

namespace Linda
{
    class ResponseOutput : 
        public MessageResponse,
        RegisterSerializable<ResponseOutput, MessageResponse>
    {
        ResponseOutput();
        ResponseOutput(bool status);

        virtual void Process(ProcessorResponse *processor);

    protected:
        virtual id_t Id() const;
    };
}

#endif	/* _RESPONSEOUTPUT_H */

