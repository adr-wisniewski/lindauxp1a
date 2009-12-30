/* 
 * File:   Query.impl.h
 * Author: adrian
 *
 * Created on 20 grudzień 2009, 13:54
 */

#ifndef _QUERY_IMPL_H
#define	_QUERY_IMPL_H

#include "Query.h"
#include <sstream>

namespace Linda
{
    template<Operation TOperator>
    struct OperationHelper
    {
        template<class TType>
        static bool OperatorSatisfied(const TType &val1,const TType &val2);

        template<class TType>
        static std::string QueryToString(const std::string typeName, TType value)
        {
            std::ostringstream buffer;
            buffer
                << typeName
                << OperationHelper<TOperator>::OperatorString()
                << " "
                << value;

            return buffer.str();
        }

        static std::string OperatorString();
    };

    template<>
    struct OperationHelper<OperationEqual>
    {
        template<class TType>
        static bool OperatorSatisfied(const TType &val1,const TType &val2)
        {
            return val1 == val2;
        }

        template<class TType>
        static std::string QueryToString(const std::string typeName, TType value);

        static std::string OperatorString()
        {
            return "=";
        }
    };

    template<>
    struct OperationHelper<OperationNotEqual>
    {
        template<class TType>
        static bool OperatorSatisfied(const TType &val1,const TType &val2)
        {
            return val1 != val2;
        }

        template<class TType>
        static std::string QueryToString(const std::string typeName, TType value);

        static std::string OperatorString()
        {
            return "!=";
        }
    };

    template<>
    struct OperationHelper<OperationLess>
    {
        template<class TType>
        static bool OperatorSatisfied(const TType &val1,const TType &val2)
        {
            return val1 < val2;
        }

        template<class TType>
        static std::string QueryToString(const std::string typeName, TType value);

        static std::string OperatorString()
        {
            return "<";
        }
    };
    
    template<>
    struct OperationHelper<OperationEqualLess>
    {
        template<class TType>
        static bool OperatorSatisfied(const TType &val1,const TType &val2)
        {
            return val1 <= val2;
        }

        template<class TType>
        static std::string QueryToString(const std::string typeName, TType value);

        static std::string OperatorString()
        {
            return "<=";
        }
    };

    template<>
    struct OperationHelper<OperationGreater>
    {
        template<class TType>
        static bool OperatorSatisfied(const TType &val1,const TType &val2)
        {
            return val1 > val2;
        }

        template<class TType>
        static std::string QueryToString(const std::string typeName, TType value);

        static std::string OperatorString()
        {
            return ">";
        }
    };

    template<>
    struct OperationHelper<OperationEqualGreater>
    {
        template<class TType>
        static bool OperatorSatisfied(const TType &val1,const TType &val2)
        {
            return val1 >= val2;
        }

        template<class TType>
        static std::string QueryToString(const std::string typeName, TType value);

        static std::string OperatorString()
        {
            return ">=";
        }
    };

    template<>
    struct OperationHelper<OperationAny>
    {
        template<class TType>
        static bool OperatorSatisfied(const TType &val1,const TType &val2)
        {
            return true;
        }

        template<class TType>
        static std::string QueryToString(const std::string typeName, TType value)
        {
            std::ostringstream buffer;
            buffer << typeName << "=*";

            return buffer.str();
        }
    };

////////////////////////////////////////////////////////////////////////////////

    template<class TType, Operation TOperation>
    ConcreteQueryValue<TType,TOperation>::ConcreteQueryValue()
    {

    }

    template<Operation TOperation>
    ConcreteQueryValue<std::string,TOperation>::ConcreteQueryValue()
    {

    }

    template<class TType, Operation TOperation>
    ConcreteQueryValue<TType,TOperation>::ConcreteQueryValue(TType value)
    : mValue(value)
    {

    }

    template<Operation TOperation>
    ConcreteQueryValue<std::string,TOperation>::ConcreteQueryValue(const std::string &value)
    : mValue(value)
    {

    }

    template<class TType, Operation TOperation>
    /*virtual*/ QueryValue* ConcreteQueryValue<TType,TOperation>::clone() const
    {
        return new ConcreteQueryValue<TType,TOperation>(mValue.Value());
    }

    template<Operation TOperation>
    /*virtual*/ QueryValue* ConcreteQueryValue<std::string,TOperation>::clone() const
    {
        return new ConcreteQueryValue<std::string,TOperation>(mValue.Value());
    }

    template<class TType, Operation TOperation>
    /*virtual*/ id_t ConcreteQueryValue<TType,TOperation>::Id() const
    {
        return ClassToId<ConcreteQueryValue<TType,TOperation> >::Id();
    }

    template<Operation TOperation>
    /*virtual*/ id_t ConcreteQueryValue<std::string,TOperation>::Id() const
    {
        return ClassToId<ConcreteQueryValue<std::string,TOperation> >::Id();
    }

    template<class TType, Operation TOperation>
    /*virtual*/ void ConcreteQueryValue<TType,TOperation>::DoSerialize(std::ostream &stream) const
    {
        stream << mValue.Value();
    }

    template<Operation TOperation>
    /*virtual*/ void ConcreteQueryValue<std::string,TOperation>::DoSerialize(std::ostream &stream) const
    {
        SerializeString(mValue.Value(), stream);
    }

    template<class TType, Operation TOperation>
    /*virtual*/ void ConcreteQueryValue<TType,TOperation>::DoUnserialize(std::istream &stream)
    {
        TType result;
        stream >> result;
        
        mValue.Value(result);
    }

    template<Operation TOperation>
    /*virtual*/ void ConcreteQueryValue<std::string,TOperation>::DoUnserialize(std::istream &stream)
    {
        mValue.Value(UnserializeString(stream));
    }

    template<class TType, Operation TOperation>
    /*virtual*/ bool ConcreteQueryValue<TType, TOperation>::IsSatisfied(const TupleValue &value) const
    {
        // must be same type
        const ConcreteTupleValue<TType> *val = dynamic_cast<const ConcreteTupleValue<TType>*>(&value);

        return val != 0 && OperationHelper<TOperation>::OperatorSatisfied(mValue.Value(), val->Value());
    }

    template<Operation TOperation>
    /*virtual*/ bool ConcreteQueryValue<std::string, TOperation>::IsSatisfied(const TupleValue &value) const
    {
        // must be same type
        const ConcreteTupleValue<std::string> *val = dynamic_cast<const ConcreteTupleValue<std::string>*>(&value);

        return val != 0 && OperationHelper<TOperation>::OperatorSatisfied(mValue.Value(), val->Value());
    }

    template<class TType, Operation TOperation>
    /*virtual*/ std::string ConcreteQueryValue<TType,TOperation>::ToString() const
    {
        return OperationHelper<TOperation>::QueryToString(mValue.GetTypeName() ,mValue.Value());
    }

    template<Operation TOperation>
    /*virtual*/ std::string ConcreteQueryValue<std::string,TOperation>::ToString() const
    {
        return OperationHelper<TOperation>::QueryToString(mValue.GetTypeName(), mValue.Value());
    }
    
    template class ConcreteQueryValue<float,OperationEqual>;
    template class ConcreteQueryValue<float,OperationNotEqual>;
    template class ConcreteQueryValue<float,OperationLess>;
    template class ConcreteQueryValue<float,OperationEqualLess>;
    template class ConcreteQueryValue<float,OperationGreater>;
    template class ConcreteQueryValue<float,OperationEqualGreater>;

    template class ConcreteQueryValue<int,OperationEqual>;
    template class ConcreteQueryValue<int,OperationNotEqual>;
    template class ConcreteQueryValue<int,OperationLess>;
    template class ConcreteQueryValue<int,OperationEqualLess>;
    template class ConcreteQueryValue<int,OperationGreater>;
    template class ConcreteQueryValue<int,OperationEqualGreater>;
    template class ConcreteQueryValue<int,OperationAny>;

    template class ConcreteQueryValue<std::string,OperationEqual>;
    template class ConcreteQueryValue<std::string,OperationNotEqual>;
    template class ConcreteQueryValue<std::string,OperationLess>;
    template class ConcreteQueryValue<std::string,OperationEqualLess>;
    template class ConcreteQueryValue<std::string,OperationGreater>;
    template class ConcreteQueryValue<std::string,OperationEqualGreater>;
    template class ConcreteQueryValue<std::string,OperationAny>;
}

#endif	/* _QUERY_IMPL_H */

