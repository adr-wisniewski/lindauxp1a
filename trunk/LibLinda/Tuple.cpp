#include "Tuple.h"

namespace Linda
{
    ConcreteTupleValue<std::string>::ConcreteTupleValue()
    {
    }

    ConcreteTupleValue<std::string>::ConcreteTupleValue(const std::string &value)
    : mValue(value)
    {
    }

    const std::string& ConcreteTupleValue<std::string>::Value() const
    {
        return mValue;
    }

    void ConcreteTupleValue<std::string>::Value(const std::string &value)
    {
        mValue = value;
    }

     /*virtual*/ void ConcreteTupleValue<std::string>::DoSerialize(std::ostream &stream) const
    {
        SerializeString(mValue, stream);
    }

    /*virtual*/ void ConcreteTupleValue<std::string>::DoUnserialize(std::istream &stream)
    {
        mValue = UnserializeString(stream);
    }

    /*virtual*/ TupleValue* ConcreteTupleValue<std::string>::clone() const
    {
        return new ConcreteTupleValue<std::string>(mValue);
    }

    /*virtual*/ id_t ConcreteTupleValue<std::string>::Id() const
    {
        return ClassToId<ConcreteTupleValue<std::string> >::Id();
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

    template class ConcreteTupleValue<std::string>;
}
