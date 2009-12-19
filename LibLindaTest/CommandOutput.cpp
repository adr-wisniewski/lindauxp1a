#include "CommandOutput.h"
#include "ProcessorCommand.h"

namespace Linda
{
namespace Test
{

    /*virtual*/ void CommandOutput::DoSerialize(std::ostream &stream) const
    {
        MessageCommand::DoSerialize(stream);
        mGivenTuple.Serialize(stream);
    }

    /*virtual*/ void CommandOutput::DoUnserialize(std::istream &stream)
    {
        MessageCommand::DoUnserialize(stream);
        mGivenTuple.Unserialize(stream);
    }

    /*virtual*/ int CommandOutput::GetCode() const
    {
        return UnserializableCommandOutput::GetCode();
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




