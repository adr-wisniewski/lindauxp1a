#include "CommandOutput.h"
#include "ProcessorCommand.h"
#include "IdTest.h"

namespace Linda
{
namespace Test
{
    CommandOutput::CommandOutput()
    {

    }

    CommandOutput::CommandOutput(int ordinal, int workerId, const Tuple &tuple)
    : MessageWorkerCommand(ordinal,workerId), mGivenTuple(tuple)
    {

    }

    /*virtual*/ void CommandOutput::DoSerialize(Archive &stream) const
    {
        MessageWorkerCommand::DoSerialize(stream);
        mGivenTuple.DoSerialize(stream);
    }

    /*virtual*/ void CommandOutput::DoUnserialize(Archive &stream)
    {
        MessageWorkerCommand::DoUnserialize(stream);
        mGivenTuple.DoUnserialize(stream);
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




