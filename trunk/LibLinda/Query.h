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


namespace Linda
{
    enum Operation
    {
        OperationEqual,
        OperationNotEqual,
        OperationLess,
        OperationEqualLess,
        OperationGreater,
        OperationEqualGreater,
        OperationAny
    };


    class QueryValue : public Serializable<QueryValue>
    {
    public:
        virtual bool IsSatisfied(const TupleValue &value) const = 0;
        virtual QueryValue* clone() const = 0;
    };
    
    // interface implementation
    template<class TType, Operation TOperation>
    class ConcreteQueryValue : QueryValue
    {
    public:
        ConcreteQueryValue(TType value);

        virtual bool IsSatisfied(const TupleValue &value) const;
        virtual QueryValue* clone() const;

    protected:
        virtual id_t Id() const;
        virtual void DoSerialize(std::ostream &stream) const;
        virtual void DoUnserialize(std::istream &stream);

        ConcreteTupleValue<TType> mValue;
    };

    QueryValue* new_clone( const QueryValue& q );

    // Query class
    class Query : public TupleBase<QueryValue>
    {
    public:
        bool IsSatisfied(const Tuple &tuple);
    };
}


#endif	/* _QUERY_H */

