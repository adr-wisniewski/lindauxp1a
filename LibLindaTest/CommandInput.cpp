#include "CommandInput.h"
#include "ProcessorCommand.h"

namespace Linda
{
namespace Test
{

    /*virtual*/ void CommandInput::DoSerialize(std::ostream &stream) const
    {
        MessageCommand::DoSerialize(stream);
        mGivenQuery.Serialize(stream);
    }

    /*virtual*/ void CommandInput::DoUnserialize(std::istream &stream)
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



