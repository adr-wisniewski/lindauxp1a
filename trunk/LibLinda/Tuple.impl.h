/* 
 * File:   TupleValue.impl.h
 * Author: adrian
 *
 * Created on 20 grudzień 2009, 15:04
 */

#ifndef _TUPLE_IMPL_H
#define	_TUPLE_IMPL_H

#include <boost/format.hpp>
#include <sstream>

#include "Exception.h"
#include "Id.h"

namespace Linda
{
    template<class TType>
    ConcreteTupleValue<TType>::ConcreteTupleValue()
    {
    }

    template<class TType>
    ConcreteTupleValue<TType>::ConcreteTupleValue(TType value)
    : mValue(value)
    {
    }

    template<class TType>
    TType ConcreteTupleValue<TType>::Value() const
    {
        return mValue;
    }

    template<class TType>
    void ConcreteTupleValue<TType>::Value(TType value)
    {
        mValue = value;
    }

    // serialization
    template<class TType>
    /*virtual*/ void ConcreteTupleValue<TType>::DoSerialize(std::ostream &stream) const
    {
        stream << mValue;
    }

    template<class TType>
    /*virtual*/ void ConcreteTupleValue<TType>::DoUnserialize(std::istream &stream)
    {
        stream >> mValue;
    }

    template<class TType>
    /*virtual*/ TupleValue* ConcreteTupleValue<TType>::clone() const
    {
        return new ConcreteTupleValue<TType>(mValue);
    }

    template<class TType>
    /*virtual*/ id_t ConcreteTupleValue<TType>::Id() const
    {
        return ClassToId<ConcreteTupleValue<TType> >::Id();
    }

    template<class TType>
    /*virtual*/ std::string ConcreteTupleValue<TType>::ToString() const
    {
        std::ostringstream buffer;
        buffer << GetTypeName() << ": " << mValue;

        return buffer.str();
    }
   
    template class ConcreteTupleValue<int>;
    template class ConcreteTupleValue<float>;
}

#endif	/* _TUPLE_IMPL_H */

