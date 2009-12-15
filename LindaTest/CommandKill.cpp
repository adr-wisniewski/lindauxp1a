/*
 * File:   CommandKill.cpp
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 13:18
 */

#include <string.h>

#include "CommandKill.h"

namespace Linda
{
namespace Test
{
    const int CommandKill::smCode = 2;

    CommandKill::CommandKill(std::string id) : CommandCreate(id)
    {
    }

    void CommandKill::Execute(CommandVisitor* visitor)
    {
        visitor->Visit(*this);
    }

    int CommandKill::GetCode() const
    {
        return CommandKill::smCode;
    }

    Command* CommandKill::Create(int bufferSize, void* buffer)
    {
        return new CommandKill(std::string(static_cast<char*>(buffer), bufferSize));
    }

}
}


