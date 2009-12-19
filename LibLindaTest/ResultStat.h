/* 
 * File:   ResultStat.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 20:28
 */

#ifndef _RESULTSTAT_H
#define	_RESULTSTAT_H

#include "MessageResult.h"

#include <list>

#include <MessageUnserializable.h>
#include <Tuple.h>
#include <Query.h>

namespace Linda
{
    namespace Test
    {

        class ResultStat;

        typedef MessageUnserializable<ResultStat, MessageResult, 2>
            UnserializableResultStat;

        class ResultStat :
            public MessageResult,
            private UnserializableResultStat
        {
        public:
            typedef std::pair<std::string, Query> AwaitingRead;

            ResultStat();
            ResultStat(
                int ordinal,
                bool status,
                std::list<Tuple> storage,
                std::list<AwaitingRead> awaitingReads
            );

            virtual void DoSerialize(std::ostream &stream) const;
            virtual void DoUnserialize(std::istream &stream);

            virtual int GetCode() const;
            virtual void Process(ProcessorResult *processor);
            
            const std::list<Tuple> Storage() const;
            const std::list<AwaitingRead> AwaitingReads();

        protected:
            std::list<Tuple>        mStorage;
            std::list<AwaitingRead> mAwaitingReads;
        };
    }
}

#endif	/* _RESULTSTAT_H */

