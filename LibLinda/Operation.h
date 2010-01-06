/* 
 * File:   Operation.h
 * Author: adrian
 *
 * Created on 30 grudzień 2009, 19:43
 */

#ifndef _OPERATION_H
#define	_OPERATION_H

#include <string>
#include <sstream>

namespace Linda
{
    enum Operation
    {
        OperationEqual,
        OperationNotEqual,
        OperationLess,
        OperationEqualLess,
        OperationGreater,
        OperationEqualGreater,
        OperationAny
    };

    /**
    * Metaprogramming pattern (trait) used for partial specialization of ConcreteQueryValue
    */
    struct OperationTraitsBase
    {
        template<class TType>
        static std::string QueryToString(
            const std::string &typeName,
            const std::string &operationSign,
            TType value
        )
        {
            std::ostringstream buffer;
            buffer
                << typeName
                << ":"
                << operationSign         
                << value;

            return buffer.str();
        }
    };

    template<Operation TOperator>
    struct OperationTraits
    {

    };

    template<>
    struct OperationTraits<OperationEqual>
    {
        template<class TType>
        static bool OperatorSatisfied(const TType &val1,const TType &val2)
        {
            return val1 == val2;
        }

        template<class TType>
        static std::string QueryToString(const std::string &typeName, TType value)
        {
            return OperationTraitsBase::QueryToString<TType>(typeName, "", value);
        }
    };

    template<>
    struct OperationTraits<OperationNotEqual>
    {
        template<class TType>
        static bool OperatorSatisfied(const TType &val1,const TType &val2)
        {
            return val1 != val2;
        }

        template<class TType>
        static std::string QueryToString(const std::string &typeName, TType value)
        {
            return OperationTraitsBase::QueryToString<TType>(typeName, "!", value);
        }
    };

    template<>
    struct OperationTraits<OperationLess>
    {
        template<class TType>
        static bool OperatorSatisfied(const TType &val1,const TType &val2)
        {
            return val1 < val2;
        }

        template<class TType>
        static std::string QueryToString(const std::string &typeName, TType value)
        {
            return OperationTraitsBase::QueryToString<TType>(typeName, "<", value);
        }
    };

    template<>
    struct OperationTraits<OperationEqualLess>
    {
        template<class TType>
        static bool OperatorSatisfied(const TType &val1,const TType &val2)
        {
            return val1 <= val2;
        }

        template<class TType>
        static std::string QueryToString(const std::string &typeName, TType value)
        {
            return OperationTraitsBase::QueryToString<TType>(typeName, "<=", value);
        }
    };

    template<>
    struct OperationTraits<OperationGreater>
    {
        template<class TType>
        static bool OperatorSatisfied(const TType &val1,const TType &val2)
        {
            return val1 > val2;
        }

        template<class TType>
        static std::string QueryToString(const std::string &typeName, TType value)
        {
            return OperationTraitsBase::QueryToString<TType>(typeName, ">", value);
        }
    };

    template<>
    struct OperationTraits<OperationEqualGreater>
    {
        template<class TType>
        static bool OperatorSatisfied(const TType &val1,const TType &val2)
        {
            return val1 >= val2;
        }

        template<class TType>
        static std::string QueryToString(const std::string &typeName, TType value)
        {
            return OperationTraitsBase::QueryToString<TType>(typeName, ">=", value);
        }
    };

    template<>
    struct OperationTraits<OperationAny>
    {
        template<class TType>
        static bool OperatorSatisfied(const TType &val1,const TType &val2)
        {
            return true;
        }

        template<class TType>
        static std::string QueryToString(const std::string &typeName, TType value)
        {
            std::ostringstream buffer;
            buffer << typeName << ":*";

            return buffer.str();
        }
    };
}

#endif	/* _OPERATION_H */

