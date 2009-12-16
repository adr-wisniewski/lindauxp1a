/* 
 * File:   ReadCommand.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 20:30
 */

#ifndef _READCOMMAND_H
#define	_READCOMMAND_H

#include "InputCommand.h"

namespace Linda
{
    namespace Test
    {
        static const int ReadCommandCode = 5;

        class ReadCommand :
            public CommandMessage,
            private UnserializableMessage<ReadCommand, CommandMessage, ReadCommandCode>
        {
        public:


        };
    }
}

#endif	/* _READCOMMAND_H */

