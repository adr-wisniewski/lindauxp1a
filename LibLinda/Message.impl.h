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
    template<class TTarget, class TProcessor>
    Message<TTarget,TProcessor>::InvalidCodeException::InvalidCodeException(int code)
    : std::runtime_error(std::string("Invalid message code: ") + boost::lexical_cast<std::string>(code))
    {
       // empty
    }

    template<class TTarget, class TProcessor>
    void Message<TTarget,TProcessor>::Serialize(std::ostream &stream) const
    {
        stream << GetCode();
        DoSerialize(stream);
    }

    template<class TTarget, class TProcessor>
    TTarget* Message<TTarget,TProcessor>::Unserialize(std::istream &stream)
    {
        int code;
        FactoryRegister &factoryRegister = 
                Message<TTarget,TProcessor>::GetFactoryRegister();
        
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

    template<class TTarget, class TProcessor>
    bool Message<TTarget,TProcessor>::RegisterFactoryMethod(
        int code, Message<TTarget,TProcessor>::Instantinator method)
    {
        Message<TTarget,TProcessor>::GetFactoryRegister()[code] = method;
        return true;
    }

    template<class TTarget, class TProcessor>
    typename Message<TTarget,TProcessor>::FactoryRegister&
        Message<TTarget,TProcessor>::GetFactoryRegister()
    {
        static FactoryRegister factoryRegister;
        return factoryRegister;
    }
}

#endif	/* _MESSAGE_IMPL_H */

