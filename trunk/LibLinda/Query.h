/* 
 * File:   Query.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 14:58
 */

#ifndef _QUERY_H
#define	_QUERY_H

#include <ostream>
#include <istream>

#include "Tuple.h"
#include "Operation.h"

namespace Linda
{
    /**
     * Query value interface
     *  provides IsSatisfied method, which checks if corresponding tuple value
     *  matches the query
     */
    class QueryValue : public Serializable<QueryValue>
    {
    public:
        virtual bool IsSatisfied(const TupleValue &value) const = 0;
        virtual QueryValue* clone() const = 0;
        virtual std::string ToString() const = 0;
    };

    inline QueryValue* new_clone( const QueryValue& q )
    {
        return q.clone();
    }
    
    /**
     * QueryValue interface implementation
     *  Implements all interface methods
     */
    template<class TType, Operation TOperation>
    class ConcreteQueryValue : public QueryValue
    {
    public:
        ConcreteQueryValue();
        ConcreteQueryValue(TType value);

        virtual bool IsSatisfied(const TupleValue &value) const;
        
        virtual QueryValue* clone() const;
        virtual std::string ToString() const;

    protected:
        // members
        virtual id_t Id() const;
        virtual void DoSerialize(std::ostream &stream) const;
        virtual void DoUnserialize(std::istream &stream);

        ConcreteTupleValue<TType> mValue;
    };

    /**
     * Partial specialization for std::string due to different serialization routine
     */
    template<Operation TOperation>
    class ConcreteQueryValue<std::string, TOperation> : public QueryValue
    {
    public:
        ConcreteQueryValue();
        ConcreteQueryValue(const std::string &value);

        virtual bool IsSatisfied(const TupleValue &value) const;

        virtual QueryValue* clone() const;
        virtual std::string ToString() const;

    protected:
        // members
        virtual id_t Id() const;
        virtual void DoSerialize(std::ostream &stream) const;
        virtual void DoUnserialize(std::istream &stream);

        ConcreteTupleValue<std::string> mValue;
    };

    /**
     * Query class is a tuple, which additionaly provides IsSatisfied method,
     * which checks if given tuple meets given requirements
     */
    class Query : public TupleBase<QueryValue>
    {
    public:
        bool IsSatisfied(const Tuple &tuple);
    };
}

#endif	/* _QUERY_H */

