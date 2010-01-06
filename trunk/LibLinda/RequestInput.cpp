#include "RequestInput.h"
#include "ProcessorRequest.h"
#include "Id.h"

namespace Linda
{

    RequestInput::RequestInput()
    {

    }

    RequestInput::RequestInput(pid_t pid, bool isRemoving, const Query &query)
    : MessageRequest(pid), mIsRemoving(isRemoving), mGivenQuery(query)
    {
    }

    /*virtual*/ void RequestInput::DoSerialize(Archive &stream) const
    {
        MessageRequest::DoSerialize(stream);
        stream << mIsRemoving;
        mGivenQuery.DoSerialize(stream);
    }

    /*virtual*/ void RequestInput::DoUnserialize(Archive &stream)
    {
        MessageRequest::DoUnserialize(stream);
        stream >> mIsRemoving;
        mGivenQuery.DoUnserialize(stream);
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

    bool RequestInput::IsRemoving() const
    {
        return mIsRemoving;
    }

    void RequestInput::IsRemoving(bool value)
    {
        mIsRemoving = value;
    }
}








