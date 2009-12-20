/* 
 * File:   CommandRead.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 20:30
 */

#ifndef _COMMANDREAD_H
#define	_COMMANDREAD_H

#include "CommandInput.h"

namespace Linda
{
    namespace Test
    {
        class CommandRead :
            public CommandInput,
            RegisterSerializable<CommandRead, MessageCommand>
        {
        public:
            CommandRead();
            CommandRead(int ordinal, pid_t pid, const Query &query);

            virtual void Process(ProcessorCommand *processor);

        protected:
            virtual id_t Id() const;
        };
    }
}

#endif	/* _COMMANDREAD_H */

