/*
 * File:   CommandKill.cpp
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 13:18
 */

#include <string.h>

#include "ResultStat.h"
#include "ProcessorResult.h"
#include "IdTest.h"

namespace Linda
{
namespace Test
{
    ResultStat::ResultStat()
    {

    }

    ResultStat::ResultStat(
        int ordinal,
        StorageList &storage,
        ReadList &awaitingReads
    ) :
        MessageResult(ordinal, Status_Ok),
        mStorage(storage),
        mAwaitingReads(awaitingReads)
    {

    }

    /*virtual*/ void ResultStat::DoSerialize(std::ostream &stream) const
    {
        // serialize storage
        stream << mStorage.size();
        for(StorageList::const_iterator i = mStorage.begin(),
            e = mStorage.end();
            i != e;
            ++i)
        {
            i->DoSerialize(stream);
        }

        // serialize reads
        stream << mAwaitingReads.size();
        for(ReadList::const_iterator i = mAwaitingReads.begin(),
            e = mAwaitingReads.end();
            i != e;
            ++i)
        {
            // serialize first
            stream << i->first;

            // serialize second
            i->second.DoSerialize(stream);
        }
    }
    /*virtual*/ void ResultStat::DoUnserialize(std::istream &stream)
    {
        int size;

        stream >> size;
        while(size--)
        {
            Tuple tuple;
            tuple.DoUnserialize(stream);
            mStorage.push_back(tuple);
        }

        stream >> size;
        while(size--)
        {
            // read workerNo
            int worker;
            stream >> worker;

            // read query
            Query query;
            query.DoUnserialize(stream);

            // add element
            mAwaitingReads.push_back(AwaitingRead(worker,query));
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
                
    const ResultStat::StorageList& ResultStat::Storage() const
    {
        return mStorage;
    }

    const ResultStat::ReadList& ResultStat::AwaitingReads()
    {
        return mAwaitingReads;
    }

}
}

