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
    /*virtual*/ void CommandCreate::DoSerialize(std::ostream &stream)
    {
        MessageCommand::DoSerialize(stream);
        stream << mId;
    }

    /*virtual*/ Message* CommandCreate::DoUnserialize(std::istream &stream)
    {
        MessageCommand::DoUnserialize(stream);
        stream >> mId;
    }

    /*virtual*/ int CommandCreate::GetCode() const
    {
        return UnserializableCommandCreate::GetCode();
    }

    /*virtual*/ void CommandCreate::Process(ProcessorCommand *processor)
    {
        processor->Process(*this);
    }

    const std::string& CommandCreate::Id() const
    {
        return mId;
    }

    void CommandCreate::Id(std::string& value)
    {
        mId = value;
    }
}
}


