/* 
 * File:   TupleBase.h
 * Author: adrian
 *
 * Created on 20 grudzień 2009, 14:03
 */

#ifndef _TUPLEBASE_H
#define	_TUPLEBASE_H


#include <string>
#include <list>
#include <ostream>
#include <istream>
#include <boost/ptr_container/ptr_vector.hpp>

namespace Linda
{
    template<class Value>
    class TupleBase
    {
    public:

        typedef boost::ptr_vector<Value> ValueList;

        // accessor
        ValueList& Values();
        const ValueList& Values() const;

        // serialization
        void Serialize(std::ostream &stream) const;
        void Unserialize(std::istream &stream);

    protected:
        ValueList mValues;
    };
}

#include "TupleBase.impl.h"

#endif	/* _TUPLEBASE_H */

