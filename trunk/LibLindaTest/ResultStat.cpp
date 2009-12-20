/*
 * File:   CommandKill.cpp
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 13:18
 */

#include <string.h>

#include "ResultStat.h"
#include "ProcessorResult.h"
#include "Id.h"

namespace Linda
{
namespace Test
{
    ResultStat::ResultStat()
    {

    }

    ResultStat::ResultStat(
        int ordinal,
        bool status,
        std::list<Tuple> storage,
        std::list<AwaitingRead> awaitingReads
    ) :
        MessageResult(ordinal, status),
        mStorage(storage),
        mAwaitingReads(awaitingReads)
    {

    }

    /*virtual*/ void ResultStat::DoSerialize(std::ostream &stream) const
    {
        // serialize storage
        stream << mStorage.size();
        for(std::list<Tuple>::const_iterator i = mStorage.begin(),
            e = mStorage.end();
            i != e;
            ++i)
        {
            i->Serialize(stream);
        }

        // serialize reads
        stream << mAwaitingReads.size();
        for(std::list<AwaitingRead>::const_iterator i = mAwaitingReads.begin(),
            e = mAwaitingReads.end();
            i != e;
            ++i)
        {
            // serialize first
            stream << i->first;

            // serialize second
            i->second.Serialize(stream);
        }
    }
    /*virtual*/ void ResultStat::DoUnserialize(std::istream &stream)
    {
        int size;

        stream >> size;
        while(size--)
        {
            Tuple tuple;
            tuple.Unserialize(stream);
            mStorage.push_back(tuple);
        }

        stream >> size;
        while(size--)
        {
            // read length
            pid_t pid;
            stream >> pid;

            // read query
            Query query;
            query.Unserialize(stream);

            // add element
            mAwaitingReads.push_back(AwaitingRead(pid,query));
        }
    }

    /*virtual*/ id_t ResultStat::Id() const
    {
        return ClassToId<ResultStat>::Id();
    }

    /*virtual*/ void ResultStat::Process(ProcessorResult *processor)
    {
        processor->Process(*this);
    }
                
    const std::list<Tuple> ResultStat::Storage() const
    {
        return mStorage;
    }

    const std::list<ResultStat::AwaitingRead> ResultStat::AwaitingReads()
    {
        return mAwaitingReads;
    }

}
}

