#include "RequestOutput.h"
#include "ProcessorRequest.h"
#include "Id.h"

namespace Linda
{

    RequestOutput::RequestOutput()
    {

    }

    RequestOutput::RequestOutput(const Tuple &tuple)
    : mGivenTuple(tuple)
    {
    }

    /*virtual*/ void RequestOutput::DoSerialize(std::ostream &stream) const
    {
        mGivenTuple.Serialize(stream);
    }

    /*virtual*/ void RequestOutput::DoUnserialize(std::istream &stream)
    {
        mGivenTuple.Unserialize(stream);
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









