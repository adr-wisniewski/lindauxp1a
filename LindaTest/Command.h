/* 
 * File:   Command.h
 * Author: adrian
 *
 * Created on 12 grudzień 2009, 23:05
 */

#ifndef _COMMAND_H
#define	_COMMAND_H

#include <stdexcept>
#include <map>
#include "CommandVisitor.h"

namespace Linda
{
    namespace Test
    {
        class Command
        {
        public:
            Command();
            virtual ~Command();

            virtual void Execute(CommandVisitor* visitor) = 0;
            virtual int GetCode() const = 0;

            virtual int GetSerializedSize() const = 0;
            virtual void Serialize(void* buffer) = 0;

            static Command* Unserialize(int type, int bufferSize, void* buffer);

            class InvalidCommandException : public std::runtime_error
            {
            public:
                InvalidCommandException(int type);
            };

            // unserialization related factory
            typedef Command* (*FactoryMethod)(int,void*);
            static bool RegisterFactoryMethod(int type, FactoryMethod method);

        private:

            // unserialization related factory
            typedef std::map<int, FactoryMethod> FactoryRegister;
            static FactoryRegister smFactoryRegister;
        };
    }
}

#endif	/* _COMMAND_H */

