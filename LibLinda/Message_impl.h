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
    template<class TTag>
    Message<TTag>::InvalidCodeException::InvalidCodeException(int code)
    : std::runtime_error(std::string("Invalid message code: ") + boost::lexical_cast<std::string>(code))
    {
       // empty
    }

    template<class TTag>
    void Message<TTag>::Serialize(std::ostream &stream)
    {
        stream << GetCode();
        DoSerialize(stream);
    }

    template<class TTag>
    Message<TTag>* Message<TTag>::Unserialize(std::istream &stream)
    {
        int code;
        FactoryRegister &factoryRegister = Message<TTag>::GetFactoryRegister();
        
        stream >> code;

        // TODO: error handling

        // find type in factory
        typename FactoryRegister::iterator iter = factoryRegister.find(code);

        // unknown type
        if(iter == factoryRegister.end())
           throw InvalidCodeException(code);

        // create command
        Message *result = (*(iter->second))(); // should be smart pointer

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

    template<class TTag>
    bool Message<TTag>::RegisterFactoryMethod(int code, Message<TTag>::Instantinator method)
    {
        Message<TTag>::GetFactoryRegister()[code] = method;
        return true;
    }

    template<class TTag>
    typename Message<TTag>::FactoryRegister& Message<TTag>::GetFactoryRegister()
    {
        static FactoryRegister factoryRegister;
        return factoryRegister;
    }
}

#endif	/* _MESSAGE_IMPL_H */

