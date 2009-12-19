/* 
 * File:   CommandKill.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 13:18
 */

#ifndef _COMMANDKILL_H
#define	_COMMANDKILL_H

#include "CommandCreate.h"
#include "MessageUnserializable.h"

namespace Linda
{
    namespace Test
    {
        class CommandKill;

        typedef MessageUnserializable<CommandKill, MessageCommand, 2>
            UnserializableCommandKill;

        class CommandKill :
            public CommandCreate,
            private UnserializableCommandKill
        {
        public:
            virtual int GetCode() const;
            virtual void Process(ProcessorCommand *processor);
        };
    }
}


#endif	/* _COMMANDKILL_H */

