/* 
 * File:   Tuple.h
 * Author: adrian
 *
 * Created on 12 grudzień 2009, 22:08
 */

#ifndef _TUPLE_H
#define	_TUPLE_H

#include "TupleBase.h"
#include "Serializable.h"
#include <boost/noncopyable.hpp>
#include <string>
#include <ostream>

namespace Linda
{
    // interface
    class TupleValue : public Serializable<TupleValue>, boost::noncopyable
    {
    public:
        virtual ~TupleValue(){}
        virtual TupleValue* clone() const = 0;
        virtual std::string ToString() const = 0;
    };

    inline TupleValue* new_clone( const TupleValue& t )
    {
        return t.clone();
    }

    // interface implementation
    template<class TType>
    class ConcreteTupleValue : 
        public TupleValue,
        RegisterSerializable<ConcreteTupleValue<TType>, TupleValue>
    {
    public:
        ConcreteTupleValue();
        ConcreteTupleValue(TType value);
        virtual ~ConcreteTupleValue(){}

        TType Value() const;
        void Value(TType value);

        virtual TupleValue* clone() const;
        virtual std::string ToString() const;

        std::string GetTypeName() const;

    protected:
        virtual id_t Id() const;
        virtual void DoSerialize(Archive &stream) const;
        virtual void DoUnserialize(Archive &stream);

        
        
        TType mValue;
    };

    // interface implementation
    // specialization for std::string
    template<>
    class ConcreteTupleValue<std::string> : 
        public TupleValue,
        RegisterSerializable<ConcreteTupleValue<std::string>,TupleValue>
    {
    public:
        ConcreteTupleValue();
        ConcreteTupleValue(const std::string &value);

        const std::string& Value() const;
        void Value(const std::string &value);

        virtual TupleValue* clone() const;
        virtual std::string ToString() const;

        std::string GetTypeName() const;

    protected:
        virtual id_t Id() const;
        virtual void DoSerialize(Archive &stream) const;
        virtual void DoUnserialize(Archive &stream);

        std::string mValue;
    };

    /**
     * Tuple class - doesn't add any functionality to TupleBase
     */
    typedef TupleBase<TupleValue> Tuple;
}

#endif	/* _TUPLE_H */

