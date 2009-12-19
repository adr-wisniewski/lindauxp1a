#include "CommandInput.h"

namespace Linda
{
namespace Test
{

    /*virtual*/ void CommandInput::DoSerialize(std::ostream &stream)
    {
        MessageCommand::DoSerialize(stream);
        mGivenQuery.Serialize(stream);
    }

    /*virtual*/ Message* CommandInput::DoUnserialize(std::istream &stream)
    {
        MessageCommand::DoUnserialize(stream);
        mGivenQuery.Unserialize(stream);
    }

    /*virtual*/ int CommandInput::GetCode() const
    {
        return UnserializableCommandInput::GetCode();
    }

    /*virtual*/ void CommandInput::Process(ProcessorCommand *processor)
    {
        processor->Process(*this);
    }

    const Query CommandInput::GivenQuery() const
    {
        return mGivenQuery;
    }

    void CommandInput::GivenQuery(const Query& query)
    {
        mGivenQuery = query;
    }

}
}



