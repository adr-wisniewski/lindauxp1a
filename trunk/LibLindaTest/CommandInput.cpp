#include "CommandInput.h"
#include "ProcessorCommand.h"
#include "Id.h"

namespace Linda
{
namespace Test
{
    CommandInput::CommandInput()
    {

    }

    CommandInput::CommandInput(int ordinal, pid_t pid, const Query &query)
    : MessageWorkerCommand(ordinal, pid), mGivenQuery(query)
    {

    }

    /*virtual*/ void CommandInput::DoSerialize(std::ostream &stream) const
    {
        MessageWorkerCommand::DoSerialize(stream);
        mGivenQuery.Serialize(stream);
    }

    /*virtual*/ void CommandInput::DoUnserialize(std::istream &stream)
    {
        MessageWorkerCommand::DoUnserialize(stream);
        mGivenQuery.Unserialize(stream);
    }

    /*virtual*/ id_t CommandInput::Id() const
    {
        return ClassToId<CommandInput>::Id();
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



