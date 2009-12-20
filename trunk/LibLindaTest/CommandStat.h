/* 
 * File:   CommandStat.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 13:18
 */

#ifndef _COMMANDSTAT_H
#define	_COMMANDSTAT_H

#include "MessageCommand.h"

namespace Linda
{
    namespace Test
    {
        class CommandStat :
            public MessageCommand,
            private RegisterSerializable<CommandStat, MessageCommand>
        {
        public:
            CommandStat();
            CommandStat(int ordinal);

            virtual void Process(ProcessorCommand *processor);

        protected:
            virtual id_t Id() const;
        };
    }
}


#endif	/* _COMMANDSTAT_H */

