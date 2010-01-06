#include "RequestOutput.h"
#include "ProcessorRequest.h"
#include "Id.h"

namespace Linda
{

    RequestOutput::RequestOutput()
    {

    }

    RequestOutput::RequestOutput(pid_t pid, const Tuple &tuple)
    : MessageRequest(pid), mGivenTuple(tuple)
    {
    }

    /*virtual*/ void RequestOutput::DoSerialize(Archive &stream) const
    {
        MessageRequest::DoSerialize(stream);
        mGivenTuple.DoSerialize(stream);
    }

    /*virtual*/ void RequestOutput::DoUnserialize(Archive &stream)
    {
        MessageRequest::DoUnserialize(stream);
        mGivenTuple.DoUnserialize(stream);
    }

    /*virtual*/ id_t RequestOutput::Id() const
    {
        return ClassToId<RequestOutput>::Id();
    }

    /*virtual*/ void RequestOutput::Process(ProcessorRequest *processor)
    {
        processor->Process(*this);
    }

    const Tuple& RequestOutput::GivenTuple() const
    {
        return mGivenTuple;
    }

    void RequestOutput::GivenTuple(const Tuple& value)
    {
        mGivenTuple = value;
    }
}









