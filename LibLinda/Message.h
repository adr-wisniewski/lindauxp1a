/* 
 * File:   Message.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 17:00
 */

#ifndef _MESSAGE_H
#define	_MESSAGE_H

#include <ostream>
#include <istream>
#include <stdexcept>
#include <map>

namespace Linda
{
    template<class TTag>
    class Message
    {
    public:

        // type declarations
        typedef Message*    (*Instantinator)();

        // construction and destruction
        Message();
        virtual ~Message();

        // methods
        void Serialize(std::ostream &stream);
        virtual int GetCode() const = 0;

        class InvalidCodeException : public std::runtime_error
        {
        public:
            InvalidCodeException(int code);
        };

        // statics
        static Message* Unserialize(std::istream &stream);
        static bool RegisterFactoryMethod(int type, Instantinator method);

    protected:

        // seriallization
        virtual void DoSerialize(std::ostream &stream) = 0;
        virtual Message* DoUnserialize(std::istream &stream) = 0;

    private:

        // unserialization related factory
        typedef std::map<int, Instantinator> FactoryRegister;
        FactoryRegister& GetFactoryRegister();
    };
}

#include "Message_impl.h"

#endif	/* _MESSAGE_H */

