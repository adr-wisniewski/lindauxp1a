/* 
 * File:   Command.h
 * Author: adrian
 *
 * Created on 12 grudzień 2009, 23:05
 */

#ifndef _COMMAND_H
#define	_COMMAND_H

#include <Message.h>

namespace Linda
{
    namespace Test
    {
        struct Command_tag
        {

        };

        class CommandMessage : Message<Command_tag>
        {
        protected:
            int mCommandOrdinal;
        };

        typedef Pipe<CommandMessage> CommandPipe;
    }
}

#endif	/* _COMMAND_H */

