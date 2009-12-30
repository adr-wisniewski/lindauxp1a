#include "CommandRead.h"
#include "ProcessorCommand.h"
#include "Id.h"

namespace Linda
{
namespace Test
{

    CommandRead::CommandRead()
    {

    }

    CommandRead::CommandRead(int ordinal, pid_t pid, const Query &query)
    : CommandInput(ordinal, pid, query)
    {

    }

    /*virtual*/ void CommandRead::Process(ProcessorCommand *processor)
    {
        processor->Process(*this);
    }

    /*virtual*/ id_t CommandRead::Id() const
    {
        return ClassToId<CommandRead>::Id();
    }


}
}



