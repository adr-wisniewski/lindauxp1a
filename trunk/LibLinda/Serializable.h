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
        void Serialize(std::ostream &stream) const;
        static boost::shared_ptr<TType> Unserialize(std::istream &stream);

        // registering
        static bool RegisterCreator(id_t id, Creator creator);

    protected:

        // virtuals
        virtual id_t Id() const = 0;
        virtual void DoSerialize(std::ostream &stream) const = 0;
        virtual void DoUnserialize(std::istream &stream) = 0;

    private:
        static Register& GetRegister();
    };

     /**
     * CRTP patter for automatic registering serizalizables in factory
     */
    template<class TMessage, class TBase>
    class RegisterSerializable
    {
        static bool IsRegistered;
    };

    void SerializeString(const std::string &s, std::ostream &stream);
    std::string UnserializeString(std::istream &stream);
}

#include "Serializable.impl.h"

#endif	/* _SERIALIZABLE_H */

