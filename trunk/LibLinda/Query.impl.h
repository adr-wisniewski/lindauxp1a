/* 
 * File:   Query.impl.h
 * Author: adrian
 *
 * Created on 20 grudzień 2009, 13:54
 */

#ifndef _QUERY_IMPL_H
#define	_QUERY_IMPL_H

#include "Query.h"

namespace Linda
{
    template<class TType, Operation TOperation>
    ConcreteQueryValue<TType,TOperation>::ConcreteQueryValue(TType value)
    : mValue(value)
    {

    }

    template<class TType, Operation TOperation>
    /*virtual*/ QueryValue* ConcreteQueryValue<TType,TOperation>::clone() const
    {
        return new ConcreteQueryValue<TType,TOperation>(mValue.Value());
    }

    template<class TType, Operation TOperation>
    /*virtual*/ id_t ConcreteQueryValue<TType,TOperation>::RequestInput::Id() const
    {
        return ClassToId<ConcreteQueryValue<TType,TOperation> >::Id();
    }

    template<class TType, Operation TOperation>
    /*virtual*/ void ConcreteQueryValue<TType,TOperation>::DoSerialize(std::ostream &stream) const
    {
        stream << mValue.Value();
    }

    template<Operation TOperation>
    /*virtual*/ void ConcreteQueryValue<std::string, TOperation>::DoSerialize(std::ostream &stream) const
    {
        SerializeString(mValue.Value(), stream);
    }

    template<class TType, Operation TOperation>
    /*virtual*/ void ConcreteQueryValue<TType,TOperation>::DoUnserialize(std::istream &stream)
    {
        TType val;
        stream >> val

        mValue.Value(val);
    }

    template<Operation TOperation>
    /*virtual*/ void ConcreteQueryValue<std::string, TOperation>::DoUnserialize(std::ostream &stream) const
    {
        mValue.Value(UnserializeString(stream));
    }

    template<class TType, OperationEqual>
    /*virtual*/ bool ConcreteQueryValue<TType>::IsSatisfied(const TupleValue &value) const
    {
        // must be same type
        ConcreteTupleValue<TType> *val = dynamic_cast<ConcreteTupleValue<TType>*>(value);

        return val != 0 && val.Value() == mValue.Value();
    }

    template<class TType, OperationNotEqual>
    /*virtual*/ bool ConcreteQueryValue<TType>::IsSatisfied(const TupleValue *value)
    {
        // must be same type
        ConcreteTupleValue<TType> *val = dynamic_cast<ConcreteTupleValue<TType>*>(value);

        return val != 0 && val->Value() != mValue.Value();
    }

    template<class TType, OperationLess>
    /*virtual*/ bool ConcreteQueryValue<TType>::IsSatisfied(const TupleValue *value)
    {
        // must be same type
        ConcreteTupleValue<TType> *val = dynamic_cast<ConcreteTupleValue<TType>*>(value);

        return val != 0 && val->Value() < mValue.Value();
    }

    template<class TType, OperationEqualLess>
    /*virtual*/ bool ConcreteQueryValue<TType>::IsSatisfied(const TupleValue *value)
    {
        // must be same type
        ConcreteTupleValue<TType> *val = dynamic_cast<ConcreteTupleValue<TType>*>(value);

        return val != 0 && val->Value() <= mValue.Value();
    }

    template<class TType, OperationGreater>
    /*virtual*/ bool ConcreteQueryValue<TType>::IsSatisfied(const TupleValue *value)
    {
        // must be same type
        ConcreteTupleValue<TType> *val = dynamic_cast<ConcreteTupleValue<TType>*>(value);

        return val != 0 && val->Value() > mValue.Value();
    }


    template<class TType, OperationEqualGreater>
    /*virtual*/ bool ConcreteQueryValue<TType>::IsSatisfied(const TupleValue *value)
    {
        // must be same type
        ConcreteTupleValue<TType> *val = dynamic_cast<ConcreteTupleValue<TType>*>(value);

        return val != 0 && val->Value() >= mValue.Value();
    }

    template<class TType, OperationAny>
    /*virtual*/ bool ConcreteQueryValue<TType>::IsSatisfied(const TupleValue *value)
    {
        // must be same type
        ConcreteTupleValue<TType> *val = dynamic_cast<ConcreteTupleValue<TType>*>(value);

        return val != 0;
    }
}

#endif	/* _QUERY_IMPL_H */

