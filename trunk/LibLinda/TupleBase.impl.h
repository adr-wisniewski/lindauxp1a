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
    void TupleBase<Value>::DoSerialize(std::ostream &stream) const
    {
        // write size
        stream << mValues.size();

        // write values
        for(typename ValueList::const_iterator i = mValues.begin(), e = mValues.end();i != e;++i)
            i->Serialize(stream);
    }

    template<class Value>
    void TupleBase<Value>::DoUnserialize(std::istream &stream)
    {
        // read size and create values
        size_t size;
        stream >> size;

        while( size-- > 0)
            mValues.push_back(Serializable<Value>::Unserialize(stream).get());
    }

    template<class Value>
    std::ostream &operator<<(std::ostream &stream, const TupleBase<Value> &ob)
    {
        stream << "(";

        bool first = true;
        for(typename TupleBase<Value>::ValueList::const_iterator i = ob.Values().begin(), e = ob.Values().end();i != e;++i)
        {
            if(!first)
            {
                stream << ",";
            }

            stream << " " << i->ToString();

            first = false;
        }

        stream << ")";
    }
}

#endif	/* _TUPLEBASE_IMPL_H */

