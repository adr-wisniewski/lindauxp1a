#include <stdexcept>

#include "Command.h"

namespace Linda
{

namespace Test
{

    Command::FactoryRegister Command::smFactoryRegister = Command::FactoryRegister();

    Command::Command()
    {
        // empty
    }

    Command::~Command()
    {
        // empty
    }

    bool Command::RegisterFactoryMethod(int type, FactoryMethod method)
    {
        smFactoryRegister[type] = method;
        return true;
    }

    Command* Command::Unserialize(int type, int bufferSize, void* buffer)
    {
        // find type in factory
        FactoryRegister::iterator iter = smFactoryRegister.find(type);

        // unknown type
        if(iter == smFactoryRegister.end())
           throw InvalidCommandException(type);

        // create command
        return (*(iter->second))(bufferSize, buffer);
    }

    Command::InvalidCommandException::InvalidCommandException(int type)
        : std::runtime_error(std::string("Invalid command type: ") + type)
    {
       // empty
    }
}

}
