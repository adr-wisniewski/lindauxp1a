#include "ResponseInput.h"
#include "ProcessorResponse.h"

namespace Linda
{
    ResponseInput::ResponseInput()
    {

    }

    ResponseInput::ResponseInput(bool status, const Tuple& tuple)
    : MessageResponse(status), mGivenTuple(tuple)
    {
    }

    /*virtual*/ void ResponseInput::DoSerialize(std::ostream &stream) const
    {
        MessageResponse::DoSerialize(stream);
        mGivenTuple.Serialize(stream);
    }

    /*virtual*/ void ResponseInput::DoUnserialize(std::istream &stream)
    {
        MessageResponse::DoUnserialize(stream);
        mGivenTuple.Unserialize(stream);
    }

    /*virtual*/ int ResponseInput::GetCode() const
    {
        return UnserializableResponseInput::GetCode();
    }

    /*virtual*/ void ResponseInput::Process(ProcessorResponse *processor)
    {
        processor->Process(*this);
    }

    const Tuple& ResponseInput::GivenTuple() const
    {
        return mGivenTuple;
    }

    void ResponseInput::GivenTuple(const Tuple& value)
    {
        mGivenTuple = value;
    }
}







