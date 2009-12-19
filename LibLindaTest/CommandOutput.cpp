#include "CommandOutput.h"

namespace Linda
{
namespace Test
{

    /*virtual*/ void CommandOutput::DoSerialize(std::ostream &stream)
    {
        MessageCommand::DoSerialize(stream);
        mGivenTuple.Serialize(stream);
    }

    /*virtual*/ Message* CommandOutput::DoUnserialize(std::istream &stream)
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

    const Tuple CommandOutput::GivenTuple() const
    {
        return mGivenTuple;
    }

    void CommandOutput::GivenTuple(const Tuple& query)
    {
        mGivenTuple = query;
    }

}
}




