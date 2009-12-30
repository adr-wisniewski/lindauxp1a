/*
 * File:   CommandCreate.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 13:18
 */

#ifndef _COMMANDCREATE_H
#define	_COMMANDCREATE_H

#include "MessageWorkerCommand.h"

namespace Linda
{
    namespace Test
    {
        class CommandCreate :
            public MessageWorkerCommand,
            RegisterSerializable<CommandCreate, MessageCommand>
        {
        public:
            CommandCreate();
            CommandCreate(int ordinal, int workerId);

            virtual void Process(ProcessorCommand *processor);

        protected:
            virtual id_t Id() const;
        };
    }
}


#endif	/* _COMMANDCREATE_H */

