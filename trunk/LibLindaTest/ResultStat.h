/* 
 * File:   ResultStat.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 20:28
 */

#ifndef _RESULTSTAT_H
#define	_RESULTSTAT_H

#include "MessageResult.h"

#include <unistd.h>
#include <list>
#include <Tuple.h>
#include <Query.h>

namespace Linda
{
    namespace Test
    {
        class ResultStat :
            public MessageResult,
            RegisterSerializable<ResultStat, MessageResult>
        {
        public:
            typedef std::pair<int, Query>   AwaitingRead;
            typedef std::list<Tuple>        StorageList;
            typedef std::list<AwaitingRead> ReadList;

            ResultStat();
            ResultStat(
                int ordinal,
                StorageList &storage,
                ReadList &awaitingReads
            );

            virtual void Process(ProcessorResult *processor);
            
            const StorageList& Storage() const;
            const ReadList& AwaitingReads();

        protected:
            virtual id_t Id() const;
            virtual void DoSerialize(std::ostream &stream) const;
            virtual void DoUnserialize(std::istream &stream);

            std::list<Tuple>        mStorage;
            std::list<AwaitingRead> mAwaitingReads;
        };
    }
}

#endif	/* _RESULTSTAT_H */

