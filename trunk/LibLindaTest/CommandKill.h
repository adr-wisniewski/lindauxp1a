/* 
 * File:   CommandKill.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 13:18
 */

#ifndef _COMMANDKILL_H
#define	_COMMANDKILL_H

#include "MessageWorkerCommand.h"

namespace Linda
{
    namespace Test
    {
        class CommandKill :
            public MessageWorkerCommand,
            RegisterSerializable<CommandKill, MessageCommand>
        {
        public:
            CommandKill();
            CommandKill(int ordinal, pid_t pid);

            virtual void Process(ProcessorCommand *processor);

        protected:
            virtual id_t Id() const;
        };
    }
}


#endif	/* _COMMANDKILL_H */

