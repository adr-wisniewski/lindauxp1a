/* 
 * File:   KillCommand.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 13:18
 */

#ifndef _KILLCOMMAND_H
#define	_KILLCOMMAND_H

#include "CreateCommand.h"
#include "UnserializableMessage.h"

namespace Linda
{
    namespace Test
    {
        static const int KillCommandCode = 2;

        class KillCommand :
            public CreateCommand,
            private UnserializableMessage<KillCommand, CommandMessage, KillCommandCode>
        {
        public:

        };
    }
}


#endif	/* _KILLCOMMAND_H */

