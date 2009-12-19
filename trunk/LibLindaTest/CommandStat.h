/* 
 * File:   CommandStat.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 13:18
 */

#ifndef _COMMANDSTAT_H
#define	_COMMANDSTAT_H

#include "MessageCommand.h"
#include "MessageUnserializable.h"

namespace Linda
{
    namespace Test
    {
        class CommandStat;

        typedef MessageUnserializable<CommandStat, MessageCommand, 3>
            UnserializableCommandStat;

        class CommandStat :
            public MessageCommand,
            private UnserializableCommandStat
        {
        public:
            virtual void DoSerialize(std::ostream &stream);
            virtual Message* DoUnserialize(std::istream &stream);

            virtual int GetCode() const;
            virtual void Process(ProcessorCommand *processor);

        };
    }
}


#endif	/* _COMMANDSTAT_H */

