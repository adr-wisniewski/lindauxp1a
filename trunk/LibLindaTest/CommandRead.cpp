#include "CommandRead.h"
#include "ProcessorCommand.h"

namespace Linda
{
namespace Test
{

/*virtual*/ int CommandRead::GetCode() const
{
    return UnserializableCommandRead::GetCode();
}

/*virtual*/ void CommandRead::Process(ProcessorCommand *processor)
{
    processor->Process(*this);
}


}
}




