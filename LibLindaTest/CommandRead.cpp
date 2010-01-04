#include "CommandRead.h"
#include "ProcessorCommand.h"
#include "IdTest.h"

namespace Linda
{
namespace Test
{

    CommandRead::CommandRead()
    {

    }

    CommandRead::CommandRead(int ordinal, int workerId, const Query &query)
    : CommandInput(ordinal, workerId, query)
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




