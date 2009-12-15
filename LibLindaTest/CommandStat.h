/* 
 * File:   CommandStat.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 13:18
 */

#ifndef _COMMANDSTAT_H
#define	_COMMANDSTAT_H

#include <string>
#include <Tuple.h>
#include <Query.h>
#include "Command.h"
#include "RegisteredCommand.h"

namespace Linda
{
    namespace Test
    {
        class CommandStat :
            public Command, 
            private RegisteredCommand<CommandStat>
        {
        public:
            CommandStat();
            virtual void Execute();
            virtual int GetCode() const;

            virtual int GetSerializedSize() const;
            virtual void Serialize(void* buffer);

            static Command* Create(int bufferSize, void* buffer);
            static const int smCode;

            const std::list<Linda::Tuple>& GetTuples() const;
            const std::list<Linda::Query>& GetQueries() const;

        private:
            std::list<Linda::Tuple> mTuples;
            std::list<Linda::Query> mQueries;

        };
    }
}


#endif	/* _COMMANDSTAT_H */

