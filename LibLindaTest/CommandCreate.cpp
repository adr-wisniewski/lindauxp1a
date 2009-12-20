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

    CommandCreate::CommandCreate(int ordinal)
    : MessageCommand(ordinal)
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


