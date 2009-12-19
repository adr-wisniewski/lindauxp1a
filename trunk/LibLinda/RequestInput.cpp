#include "RequestInput.h"

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

    /*virtual*/ int RequestInput::GetCode() const
    {
        return UnserializableRequestInput::GetCode();
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








