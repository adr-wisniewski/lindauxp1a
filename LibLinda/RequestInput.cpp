#include "RequestInput.h"
#include "ProcessorRequest.h"
#include "Id.h"

namespace Linda
{

    RequestInput::RequestInput()
    {

    }

    RequestInput::RequestInput(const Query &query)
    : mGivenQuery(query)
    {
    }

    /*virtual*/ void RequestInput::DoSerialize(std::ostream &stream) const
    {
        mGivenQuery.Serialize(stream);
    }

    /*virtual*/ void RequestInput::DoUnserialize(std::istream &stream)
    {
        mGivenQuery.Unserialize(stream);
    }

    /*virtual*/ id_t RequestInput::Id() const
    {
        return ClassToId<RequestInput>::Id();
    }

    /*virtual*/ void RequestInput::Process(ProcessorRequest *processor)
    {
        processor->Process(*this);
    }

    const Query& RequestInput::GivenQuery() const
    {
        return mGivenQuery;
    }

    void RequestInput::GivenQuery(const Query& value)
    {
        mGivenQuery = value;
    }
}








