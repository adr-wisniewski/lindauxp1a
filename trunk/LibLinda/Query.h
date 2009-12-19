/* 
 * File:   Query.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 14:58
 */

#ifndef _QUERY_H
#define	_QUERY_H

#include "Tuple.h"

namespace Linda
{
    class Query
    {
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

        bool Satisfies(const Tuple &tuple);

    protected:
        std::list<Value> mValues;
    };
}


#endif	/* _QUERY_H */

