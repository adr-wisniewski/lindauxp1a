/* 
 * File:   Serializable.impl.h
 * Author: adrian
 *
 * Created on 20 grudzień 2009, 17:02
 */

#ifndef _SERIALIZABLE_IMPL_H
#define	_SERIALIZABLE_IMPL_H

#include <cassert>
#include <unistd.h>
#include <boost/format.hpp>

#include "Exception.h"
#include "Util.h"

namespace Linda
{
    template<class TType>
    void Serializable<TType>::Serialize(Archive &stream) const
    {
        // write id to stream
        stream << this->Id();

        // do serialization
        this->DoSerialize(stream);
    }

    template<class TType>
    /*static*/ std::auto_ptr<TType> Serializable<TType>::Unserialize(Archive &stream)
    {
        // retrive id
        id_t id;
        stream >> id;

        Register& creators = GetRegister();

        typename Register::const_iterator i = creators.find(id);
        if(i == creators.end())
            throw Exception(boost::format("Serializable::Create - unknown id: %1%") % id);

        // create object and unserialize
        std::auto_ptr<TType> result((*i->second)());
        static_cast<Serializable<TType>*>(result.get())->DoUnserialize(stream);

        return result;
    }

    template<class TType>
    /*static*/ bool Serializable<TType>::RegisterCreator(id_t id, Creator creator)
    {
        // registration  should occur only once
        assert(GetRegister().find(id) == GetRegister().end());

        // register
        GetRegister()[id] = creator;
        return true;
    }

    template<class TType>
    /*static*/ typename Serializable<TType>::Register& Serializable<TType>::GetRegister()
    {
        static Register creators;
        return creators;
    }

    template<class TType, class TBase>
    bool RegisterSerializable<TType, TBase>::IsRegistered =
        Serializable<TBase>::RegisterCreator(
            ClassToId<TType>::Id(),
            Instantinator<TType, TBase>::Create
        );
}

#endif	/* _SERIALIZABLE_IMPL_H */

