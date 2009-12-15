/* 
 * File:   Tuple.h
 * Author: adrian
 *
 * Created on 12 grudzień 2009, 22:08
 */

#ifndef _TUPLE_H
#define	_TUPLE_H

#include <string>

namespace Linda
{
    class Tuple
    {

        class Value
        {
        public:
            enum Type
            {
                TypeFloat,
                TypeInt,
                TypeString
            };

            Type mType;

            union
            {
                float       mFloatValue;
                int         mIntValue;
                std::string mStringValue;
            };
        };
    };
}

#endif	/* _TUPLE_H */

