/* 
 * File:   Message_impl.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 19:36
 */

#ifndef _MESSAGE_IMPL_H
#define	_MESSAGE_IMPL_H

#include <string>
#include <stdexcept>
#include <boost/lexical_cast.hpp>

#include "Message.h"

namespace Linda
{
    template<class TTarget>
    Message<TTarget>::InvalidCodeException::InvalidCodeException(int code)
    : std::runtime_error(std::string("Invalid message code: ") + boost::lexical_cast<std::string>(code))
    {
       // empty
    }

    template<class TTarget>
    void Message<TTarget>::Serialize(std::ostream &stream) const
    {
        stream << GetCode();
        DoSerialize(stream);
    }

    template<class TTarget>
    TTarget* Message<TTarget>::Unserialize(std::istream &stream)
    {
        int code;
        FactoryRegister &factoryRegister = Message<TTarget>::GetFactoryRegister();
        
        stream >> code;

        // TODO: error handling

        // find type in factory
        typename FactoryRegister::iterator iter = factoryRegister.find(code);

        // unknown type
        if(iter == factoryRegister.end())
           throw InvalidCodeException(code);

        // create command
        TTarget *result = (*(iter->second))(); // should be smart pointer

        try
        {
            result->DoUnserialize(stream);
        }
        catch(...)
        {
            delete result;
            throw;
        }

        return result;
    }

    template<class TTarget>
    bool Message<TTarget>::RegisterFactoryMethod(int code, Message<TTarget>::Instantinator method)
    {
        Message<TTarget>::GetFactoryRegister()[code] = method;
        return true;
    }

    template<class TTarget>
    typename Message<TTarget>::FactoryRegister& Message<TTarget>::GetFactoryRegister()
    {
        static FactoryRegister factoryRegister;
        return factoryRegister;
    }
}

#endif	/* _MESSAGE_IMPL_H */

