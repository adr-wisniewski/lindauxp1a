/* 
 * File:   CommandCreate.cpp
 * Author: adrian
 * 
 * Created on 15 grudzień 2009, 13:18
 */

#include <string.h>

#include "CommandCreate.h"

namespace Linda
{
namespace Test
{
    const int CommandCreate::smCode = 1;

    CommandCreate::CommandCreate(std::string id) : mId(id)
    {
    }

    void CommandCreate::Execute(CommandVisitor* visitor)
    {
        visitor->Visit(*this);
    }
    
    int CommandCreate::GetCode() const
    {
        return CommandCreate::smCode;
    }

    int CommandCreate::GetSerializedSize() const
    {
        return mId.length();
    }

    void CommandCreate::Serialize(void* buffer)
    {
        memcpy(buffer, mId.c_str(), mId.length());
    }

    const std::string& CommandCreate::GetId() const
    {
        return mId;
    }

    Command* CommandCreate::Create(int bufferSize, void* buffer)
    {
        return new CommandCreate(std::string(static_cast<char*>(buffer), bufferSize));
    }


}
}


