/* 
 * File:   CommandCreate.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 13:18
 */

#ifndef _COMMANDCREATE_H
#define	_COMMANDCREATE_H

#include <string>
#include "Command.h"
#include "RegisteredCommand.h"

namespace Linda
{
    namespace Test
    {
        class CommandCreate : 
            public Command, 
            private RegisteredCommand<CommandCreate>
        {
        public:
            CommandCreate(std::string id);
            virtual void Execute();
            virtual int GetCode() const;

            virtual int GetSerializedSize() const;
            virtual void Serialize(void* buffer);

            const std::string& GetId() const;

            static Command* Create(int bufferSize, void* buffer);
            static const int smCode;

        private:
            std::string mId;

        };
    }
}


#endif	/* _COMMANDCREATE_H */

