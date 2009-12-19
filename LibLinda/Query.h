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
    class Query
    {
    public:
        class Value : public Tuple::Value
        {
        public:
            enum Operation
            {
                OperationEqual,
                OperationNotEqual,
                OperationLess,
                OperationEqualLess,
                OperationGreater,
                OperationEqualGreater
            };
        protected:
            Operation mOperation;

        };

        bool IsSatisfied(const Tuple &tuple);

        void Serialize(std::ostream &stream) const;
        void Unserialize(std::istream &stream);

    protected:
        std::list<Value> mValues;
    };
}


#endif	/* _QUERY_H */

