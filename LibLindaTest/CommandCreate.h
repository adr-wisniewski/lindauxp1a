/*
 * File:   CommandCreate.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 13:18
 */

#ifndef _COMMANDCREATE_H
#define	_COMMANDCREATE_H

#include <string>

#include "MessageCommand.h"
#include "MessageUnserializable.h"

namespace Linda
{
    namespace Test
    {
        class CommandCreate;

        typedef MessageUnserializable<CommandCreate, MessageCommand, 1>
            UnserializableCommandCreate;


        class CommandCreate :
            public MessageCommand,
            private UnserializableCommandCreate
        {
        public:
            virtual void CommandCreate::DoSerialize(std::ostream &stream);
            virtual Message* CommandCreate::DoUnserialize(std::istream &stream);

            virtual int CommandCreate::GetCode() const;
            virtual void CommandCreate::Process(ProcessorCommand *processor);

            const std::string& CommandCreate::Id() const;
            void CommandCreate::Id(std::string& value);

        private:
            std::string mId;

        };
    }
}


#endif	/* _COMMANDCREATE_H */

