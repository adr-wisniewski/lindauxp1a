#include "CommandCreate.h"
#include "ProcessorCommand.h"
#include "Id.h"

namespace Linda
{
namespace Test
{
    CommandCreate::CommandCreate()
    {

    }

    CommandCreate::CommandCreate(int ordinal, int workerId)
    : MessageWorkerCommand(ordinal,workerId)
    {

    }

    /*virtual*/ void CommandCreate::Process(ProcessorCommand *processor)
    {
        processor->Process(*this);
    }

    /*virtual*/ id_t CommandCreate::Id() const
    {
        return ClassToId<CommandCreate>::Id();
    }
}
}


