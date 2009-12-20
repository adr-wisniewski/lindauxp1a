#include "CommandOutput.h"
#include "ProcessorCommand.h"
#include "Id.h"

namespace Linda
{
namespace Test
{
    CommandOutput::CommandOutput()
    {

    }

    CommandOutput::CommandOutput(int ordinal, pid_t pid, const Tuple &tuple)
    : MessageWorkerCommand(ordinal,pid), mGivenTuple(tuple)
    {

    }

    /*virtual*/ void CommandOutput::DoSerialize(std::ostream &stream) const
    {
        MessageWorkerCommand::DoSerialize(stream);
        mGivenTuple.Serialize(stream);
    }

    /*virtual*/ void CommandOutput::DoUnserialize(std::istream &stream)
    {
        MessageWorkerCommand::DoUnserialize(stream);
        mGivenTuple.Unserialize(stream);
    }

    /*virtual*/ id_t CommandOutput::Id() const
    {
        return ClassToId<CommandOutput>::Id();
    }

    /*virtual*/ void CommandOutput::Process(ProcessorCommand *processor)
    {
        processor->Process(*this);
    }

    const Tuple& CommandOutput::GivenTuple() const
    {
        return mGivenTuple;
    }

    void CommandOutput::GivenTuple(const Tuple& query)
    {
        mGivenTuple = query;
    }

}
}




