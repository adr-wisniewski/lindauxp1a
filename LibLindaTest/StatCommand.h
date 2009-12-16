/* 
 * File:   StatCommand.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 13:18
 */

#ifndef _STATCOMMAND_H
#define	_STATCOMMAND_H

#include "CommandMessage.h"
#include "UnserializableMessage.h"

namespace Linda
{
    namespace Test
    {
        static const int StatCommandCode = 3;

        class StatCommand :
            public CommandMessage,
            private UnserializableMessage<StatCommand, CommandMessage, StatCommandCode>
        {
        public:


        };
    }
}


#endif	/* _STATCOMMAND_H */

