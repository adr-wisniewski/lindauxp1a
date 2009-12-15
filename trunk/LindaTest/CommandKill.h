/* 
 * File:   CommandKill.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 13:18
 */

#ifndef _COMMANDKILL_H
#define	_COMMANDKILL_H

#include "CommandCreate.h"
#include "RegisteredCommand.h"

namespace Linda
{
    namespace Test
    {
        class CommandKill :
            public CommandCreate,
            private RegisteredCommand<CommandKill>
        {
        public:
            CommandKill(std::string id);
            virtual void Execute();
            virtual int GetCode() const;

            static Command* Create(int bufferSize, void* buffer);
            static const int smCode;

        };
    }
}


#endif	/* _COMMANDKILL_H */

