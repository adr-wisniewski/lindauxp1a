/* 
 * File:   TupleValue.impl.h
 * Author: adrian
 *
 * Created on 20 grudzień 2009, 15:04
 */

#ifndef _TUPLE_IMPL_H
#define	_TUPLE_IMPL_H

#include <Exception.h>
#include <boost/format.hpp>

namespace Linda
{
    
    template<class TType>
    ConcreteTupleValue<TType>::ConcreteTupleValue(TType value)
    : mValue(value)
    {
    }

    template<class TType>
    const TType ConcreteTupleValue<TType>::Value() const
    {
        return mValue;
    }

    template<class TType>
    void ConcreteTupleValue<TType>::Value(TType value)
    {
        mValue = value;
    }

    template<>
    const std::string& ConcreteTupleValue<std::string>::Value() const
    {
        return mValue;
    }

    template<>
    void ConcreteTupleValue<std::string>::Value(const std::string &value)
    {
        mValue = value;
    }

    // serialization
    template<class TType>
    /*virtual*/ void ConcreteTupleValue<TType>::DoSerialize(std::ostream &stream) const
    {
        stream << mValue;
    }

    template<>
    /*virtual*/ void ConcreteTupleValue<std::string>::DoSerialize(std::ostream &stream) const
    {
        SerializeString(mValue, stream);
    }

    template<class TType>
    /*virtual*/ void ConcreteTupleValue<TType>::DoUnserialize(std::istream &stream)
    {
        stream >> mValue;
    }

    template<>
    /*virtual*/ void ConcreteTupleValue<std::string>::DoUnserialize(std::istream &stream)
    {
        mValue = UnserializeString(stream);
    }

    template<class TType>
    virtual TupleValue* ConcreteTupleValue<TType>::clone() const
    {
        return new ConcreteTupleValue<TType>(mValue);
    }
}

#endif	/* _TUPLE_IMPL_H */

