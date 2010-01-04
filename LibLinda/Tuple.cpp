#include "Tuple.h"

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

    ConcreteTupleValue<std::string>::ConcreteTupleValue()
    {
    }



    template<class TType>
    ConcreteTupleValue<TType>::ConcreteTupleValue(TType value)
    : mValue(value)
    {
    }

    ConcreteTupleValue<std::string>::ConcreteTupleValue(const std::string &value)
    : mValue(value)
    {
    }

    template<class TType>
    TType ConcreteTupleValue<TType>::Value() const
    {
        return mValue;
    }

    const std::string& ConcreteTupleValue<std::string>::Value() const
    {
        return mValue;
    }

    template<class TType>
    void ConcreteTupleValue<TType>::Value(TType value)
    {
        mValue = value;
    }

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

    /*virtual*/ void ConcreteTupleValue<std::string>::DoSerialize(std::ostream &stream) const
    {
        SerializeString(mValue, stream);
    }

    template<class TType>
    /*virtual*/ void ConcreteTupleValue<TType>::DoUnserialize(std::istream &stream)
    {
        stream >> mValue;
    }

    /*virtual*/ void ConcreteTupleValue<std::string>::DoUnserialize(std::istream &stream)
    {
        mValue = UnserializeString(stream);
    }

    template<class TType>
    /*virtual*/ TupleValue* ConcreteTupleValue<TType>::clone() const
    {
        return new ConcreteTupleValue<TType>(mValue);
    }

    /*virtual*/ TupleValue* ConcreteTupleValue<std::string>::clone() const
    {
        return new ConcreteTupleValue<std::string>(mValue);
    }

    template<class TType>
    /*virtual*/ id_t ConcreteTupleValue<TType>::Id() const
    {
        return ClassToId<ConcreteTupleValue<TType> >::Id();
    }

    /*virtual*/ id_t ConcreteTupleValue<std::string>::Id() const
    {
        return ClassToId<ConcreteTupleValue<std::string> >::Id();
    }

    template<class TType>
    /*virtual*/ std::string ConcreteTupleValue<TType>::ToString() const
    {
        std::ostringstream buffer;
        buffer << GetTypeName() << ": " << mValue;

        return buffer.str();
    }

    /*virtual*/ std::string ConcreteTupleValue<std::string>::ToString() const
    {
        std::ostringstream buffer;
        buffer << GetTypeName() << ": " << mValue;

        return buffer.str();
    }

    std::string ConcreteTupleValue<std::string>::GetTypeName() const
    {
        return std::string("string");
    }

    template<>
    std::string ConcreteTupleValue<int>::GetTypeName() const
    {
        return std::string("int");
    }

    template<>
    std::string ConcreteTupleValue<float>::GetTypeName() const
    {
        return std::string("float");
    }

    // explicit instantination of template classes
    template class ConcreteTupleValue<std::string>;
    template class ConcreteTupleValue<int>;
    template class ConcreteTupleValue<float>;
}
