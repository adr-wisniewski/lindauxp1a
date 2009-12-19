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
        class CommandRead;

        typedef MessageUnserializable<CommandRead, MessageCommand, 5>
            UnserializableCommandRead;


        class CommandRead :
            public CommandInput,
            private UnserializableCommandRead
        {
        public:
            virtual int GetCode() const;
            virtual void Process(ProcessorCommand *processor);

        };
    }
}

#endif	/* _COMMANDREAD_H */

