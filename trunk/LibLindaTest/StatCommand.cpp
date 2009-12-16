/*
 * File:   CommandStat.cpp
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 13:18
 */

#include <string.h>
#include <list>

#include "CommandStat.h"

namespace Linda
{
namespace Test
{
    const int CommandStat::smCode = 3;

    CommandStat::CommandStat()
    {
    }

    void CommandStat::Execute(CommandVisitor* visitor)
    {
        visitor->Visit(*this);
    }

    int CommandStat::GetCode() const
    {
        return CommandStat::smCode;
    }

    int CommandStat::GetSerializedSize() const
    {
        int sum = 0;

        for(std::list<Linda::Tuple>::const_iterator i = mTuples.begin(), e = mTuples.end(); i != e; ++i)
            sum += sizeof(int) + i->GetSerializedSize();

        for(std::list<Linda::Query>::const_iterator i = mQueries.begin(), e = mQueries.end(); i != e; ++i)
            sum += sizeof(int) + i->GetSerializedSize();
        
        return sum + 2 * sizeof(int);
    }

    void CommandStat::Serialize(void* buffer)
    {
        void* current = buffer;
        int tuples  = mTuples.size();
        int queries = mQueries.size();

        // serialize tuples
        memcpy(current, static_cast<void*>(&tuples), sizeof(int));
        current += sizeof(int);

        for(std::list<Linda::Tuple>::const_iterator i = mTuples.begin(), e = mTuples.end(); i != e; ++i)
        {
            int size = i->GetSerializedSize();

            memcpy(current, static_cast<void*>(&size), sizeof(int));
            current += sizeof(int);

            i->Serialize(current);
            current += size;
        }

        // serialize queries
        memcpy(current, static_cast<void*>(&queries), sizeof(int));
        current += sizeof(int);

        for(std::list<Linda::Query>::const_iterator i = mQueries.begin(), e = mQueries.end(); i != e; ++i)
        {
            int size = i->GetSerializedSize();

            memcpy(current, static_cast<void*>(&size), sizeof(int));
            current += sizeof(int);

            i->Serialize(current);
            current += size;
        }
    }

    const std::list<Linda::Tuple>& CommandStat::GetTuples() const
    {
        return mTuples;
    }

    const std::list<Linda::Query>& CommandStat::GetQueries() const
    {
        return mQueries;
    }

    Command* CommandStat::Create(int bufferSize, void* buffer)
    {
        CommandStat *result = new CommandStat();

        void *current = buffer;

        int tuples;
        int queries;
        int size;

        // unserialize tuples
        memcpy(static_cast<void*>(&tuples), current, sizeof(int));
        current += sizeof(int);

        while(--tuples > 0)
        {
            memcpy(static_cast<void*>(&size), current, sizeof(int));
            current += sizeof(int);

            // this should not be a pointer
            Tuple *tuple = Tuple::Unserialize(size, current);
            result.mTuples.push_back(*tuple);
            delete tuple;

            current += size;
        }

        // unserialize queries
        memcpy(static_cast<void*>(&queries), current, sizeof(int));
        current += sizeof(int);

        while(--queries > 0)
        {
            memcpy(static_cast<void*>(&size), current, sizeof(int));
            current += sizeof(int);

            // this should not be a pointer
            Query *query = Query::Unserialize(size, current);
            result.mTuples.push_back(*query);
            delete query;

            current += size;
        }
    }
}
}


