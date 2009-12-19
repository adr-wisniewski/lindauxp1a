/* 
 * File:   RequestOutput.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 17:07
 */

#ifndef _REQUESTOUTPUT_H
#define	_REQUESTOUTPUT_H

#include "MessageRequest.h"
#include "MessageUnserializable.h"
#include "Tuple.h"

namespace Linda
{
    class RequestOutput;

    typedef MessageUnserializable<RequestOutput, MessageRequest, 2>
            UnserializableRequestOutput;

    class RequestOutput : 
        public MessageRequest,
        private UnserializableRequestOutput
    {
        public:
        RequestOutput();
        RequestOutput(const Tuple &tuple);

        virtual void DoSerialize(std::ostream &stream) const;
        virtual void DoUnserialize(std::istream &stream);

        virtual int GetCode() const;

        const Tuple& GivenTuple() const;
        void GivenTuple(const Tuple& value);

    protected:
        Tuple mGivenTuple;
    };
}

#endif	/* _REQUESTOUTPUT_H */

