/* 
 * File:   TupleBase.impl.h
 * Author: adrian
 *
 * Created on 20 grudzień 2009, 14:04
 */

#ifndef _TUPLEBASE_IMPL_H
#define	_TUPLEBASE_IMPL_H

#include "Serializable.h"

namespace Linda
{
  
    template<class Value>
    typename TupleBase<Value>::ValueList& TupleBase<Value>::Values()
    {
        return const_cast<ValueList&>(const_cast<const TupleBase*>(this)->Values());
    }

    template<class Value>
    const typename TupleBase<Value>::ValueList& TupleBase<Value>::Values() const
    {
        return mValues;
    }

    // serialization
    template<class Value>
    void TupleBase<Value>::Serialize(std::ostream &stream) const
    {
        // write size
        stream << mValues.size();

        // write values
        for(typename ValueList::const_iterator i = mValues.begin(), e = mValues.end();i != e;++i)
            i->Serialize(stream);
    }

    template<class Value>
    void TupleBase<Value>::Unserialize(std::istream &stream)
    {
        // read size and create values
        size_t size;
        stream >> size;

        while( size-- > 0)
            mValues.push_back(Serializable<Value>::Unserialize(stream));
    }
}

#endif	/* _TUPLEBASE_IMPL_H */

