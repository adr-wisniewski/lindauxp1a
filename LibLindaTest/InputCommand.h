/* 
 * File:   InputCommand.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 20:30
 */

#ifndef _INPUTCOMMAND_H
#define	_INPUTCOMMAND_H

#include "CommandMessage.h"
#include "UnserializableMessage.h"

namespace Linda
{
    namespace Test
    {
        static const int InputCommandCode = 4;

        class InputCommand :
            public CommandMessage,
            private UnserializableMessage<InputCommand, CommandMessage, InputCommandCode>
        {
        public:


        };
    }
}

#endif	/* _INPUTCOMMAND_H */

