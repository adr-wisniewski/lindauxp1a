/* 
 * File:   Serializable.h
 * Author: adrian
 *
 * Created on 20 grudzień 2009, 17:00
 */

#ifndef _SERIALIZABLE_H
#define	_SERIALIZABLE_H

#include <map>
#include <istream>
#include <ostream>
#include <string>
#include <boost/shared_ptr.hpp>
#include <memory>

#include "Archive.h"

namespace Linda
{
    typedef int id_t;

    /**
     * Template providing object creation method
     */
    template<class TType, class TBase>
    struct Instantinator
    {
        static TBase* Create()
        {
            return new TType();
        }
    };

    /**
     * Template providing Id for each seriallizable class
     */
    template<class TType>
    struct ClassToId
    {
        static id_t Id();
    };

    /**
     * Interface for serializable objects
     */
    template<class TType>
    class Serializable
    {
    public:
        virtual ~Serializable(){};

        typedef TType*(*Creator)();
        typedef std::map<id_t, Creator> Register;

        // interface
        void Serialize(Archive &stream) const;
        static std::auto_ptr<TType> Unserialize(Archive &stream);

        // registering
        static bool RegisterCreator(id_t id, Creator creator);

    protected:

        // virtuals
        virtual id_t Id() const = 0;
        virtual void DoSerialize(Archive &stream) const = 0;
        virtual void DoUnserialize(Archive &stream) = 0;

    private:
        static Register& GetRegister();
    };

     /**
     * CRTP patter for automatic registering serizalizables in factory
     */
    template<class TMessage, class TBase>
    class RegisterSerializable
    {
    public:
        RegisterSerializable()
        {
            assert(IsRegistered);
            IsRegistered; // instantinate
        }

        static bool IsRegistered;
    };
}

#include "Serializable.impl.h"

#endif	/* _SERIALIZABLE_H */

