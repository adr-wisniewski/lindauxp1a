/* 
 * File:   RequestOutput.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 17:07
 */

#ifndef _REQUESTOUTPUT_H
#define	_REQUESTOUTPUT_H

#include "MessageRequest.h"
#include "Tuple.h"


namespace Linda
{
    /**
     * Linda Output request for given tuple
     */
    class RequestOutput : 
        public MessageRequest,
        RegisterSerializable<RequestOutput, MessageRequest>
    {
    public:
        RequestOutput();
        RequestOutput(const Tuple &tuple);

        virtual void Process(ProcessorRequest *processor);

        const Tuple& GivenTuple() const;
        void GivenTuple(const Tuple& value);

    protected:
        virtual id_t Id() const;
        virtual void DoSerialize(std::ostream &stream) const;
        virtual void DoUnserialize(std::istream &stream);

        Tuple mGivenTuple;
    };
}

#endif	/* _REQUESTOUTPUT_H */

