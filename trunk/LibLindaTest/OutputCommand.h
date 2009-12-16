/* 
 * File:   OutputCommand.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 20:30
 */

#ifndef _OUTPUTCOMMAND_H
#define	_OUTPUTCOMMAND_H

#include "CommandMessage.h"
#include "UnserializableMessage.h"

namespace Linda
{
    namespace Test
    {
        static const int OutputCommandCode = 6;

        class OutputCommand :
            public CommandMessage,
            private UnserializableMessage<OutputCommand, CommandMessage, OutputCommandCode>
        {
        public:


        };
    }
}

#endif	/* _OUTPUTCOMMAND_H */

