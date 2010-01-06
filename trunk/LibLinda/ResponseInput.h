/* 
 * File:   ResponseInput.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 19:02
 */

#ifndef _RESPONSEINPUT_H
#define	_RESPONSEINPUT_H

#include "MessageResponse.h"
#include "Tuple.h"

namespace Linda
{
    /**
     * Linda Input response for all Input operations ( input and read )
     */
    class ResponseInput : 
        public MessageResponse,
        RegisterSerializable<ResponseInput, MessageResponse>
    {
    public:
        ResponseInput();
        ResponseInput(bool status, const Tuple& tuple);

        virtual void Process(ProcessorResponse *processor);

        const Tuple& GivenTuple() const;
        void GivenTuple(const Tuple& value);

    protected:
        virtual id_t Id() const;
        virtual void DoSerialize(Archive &stream) const;
        virtual void DoUnserialize(Archive &stream);

        Tuple mGivenTuple;
    };
}

#endif	/* _RESPONSEINPUT_H */

