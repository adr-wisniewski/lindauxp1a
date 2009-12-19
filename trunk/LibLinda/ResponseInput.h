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
#include "Tuple.h"

namespace Linda
{
    class ResponseInput;

    typedef MessageUnserializable<ResponseInput, MessageResponse, 1>
            UnserializableResponseInput;

    class ResponseInput : 
        public MessageResponse,
        private UnserializableResponseInput
    {
    public:
        ResponseInput();
        ResponseInput(bool status, const Tuple& tuple);

        virtual void DoSerialize(std::ostream &stream) const;
        virtual void DoUnserialize(std::istream &stream);

        virtual int GetCode() const;
        virtual void Process(ProcessorResponse *processor);

        const Tuple& GivenTuple() const;
        void GivenTuple(const Tuple& value);

    protected:
        Tuple mGivenTuple;
    };
}

#endif	/* _RESPONSEINPUT_H */

