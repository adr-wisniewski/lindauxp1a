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

namespace Linda
{
    // interface
    class TupleValue : public Serializable<TupleValue>, boost::noncopyable
    {
    public:
        virtual TupleValue* clone() const = 0;
    };

    // interface implementation
    template<class TType>
    class ConcreteTupleValue : 
        public TupleValue,
        RegisterSerializable<ConcreteTupleValue<TType>, TupleValue>
    {
    public:

        ConcreteTupleValue(TType value);

        TType Value() const;
        void Value(TType value);

        virtual TupleValue* clone() const;

    protected:
        virtual id_t Id() const;
        virtual void DoSerialize(std::ostream &stream) const;
        virtual void DoUnserialize(std::istream &stream);
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
        ConcreteTupleValue(std::string value);

        const std::string& Value() const;
        void Value(const std::string &value);

        virtual TupleValue* clone() const;

    protected:
        virtual void DoSerialize(std::ostream &stream) const;
        virtual void DoUnserialize(std::istream &stream);

        std::string mValue;
    };

    TupleValue* new_clone( const TupleValue& t );

    typedef TupleBase<TupleValue> Tuple;
}

#endif	/* _TUPLE_H */

