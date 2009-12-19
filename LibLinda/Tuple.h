/* 
 * File:   Tuple.h
 * Author: adrian
 *
 * Created on 12 grudzień 2009, 22:08
 */

#ifndef _TUPLE_H
#define	_TUPLE_H

#include <string>
#include <list>
#include <ostream>
#include <istream>

namespace Linda
{
    class Tuple
    {
    public:
        // this should be abstract + visitor
        class Value
        {
        public:

            enum Type
            {
                TypeFloat,
                TypeInt,
                TypeString
            };

            // construction and destruction
            Value(float value);
            Value(int value);
            Value(const std::string &value);

            ~Value();

            // accessors
            Type                GetType() const;
            float               ValueFloat() const;
            int                 ValueInt() const;
            const std::string&  ValueString() const;

        protected:

            Type mType;

            union
            {
                float       mFloatValue;
                int         mIntValue;
                std::string* mStringValue;
            };
        };

        void Serialize(std::ostream &stream) const;
        void Unserialize(std::istream &stream);

    protected:
        std::list<Value> mValues;
    };
}

#endif	/* _TUPLE_H */

