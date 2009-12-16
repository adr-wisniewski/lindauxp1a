/* 
 * File:   CreateCommand.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 13:18
 */

#ifndef _CREATECOMMAND_H
#define	_CREATECOMMAND_H

#include <string>

#include "CommandMessage.h"
#include "UnserializableMessage.h"

namespace Linda
{
    namespace Test
    {
        static const int CreateCommandCode = 1;

        class CreateCommand :
            public CommandMessage,
            private UnserializableMessage<CreateCommand, CommandMessage, CreateCommandCode>
        {
        public:


        private:
            std::string mId;

        };
    }
}


#endif	/* _CREATECOMMAND_H */

