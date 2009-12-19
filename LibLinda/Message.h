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
    template<class TTarget, class TProcessor>
    class Message
    {
    public:

        // type declarations
        typedef TTarget*    (*Instantinator)();

        // construction and destruction
        Message();
        virtual ~Message();

        // methods
        void Serialize(std::ostream &stream) const;
        virtual int GetCode() const = 0;
        virtual void Process(TProcessor* processor) = 0;

        class InvalidCodeException : public std::runtime_error
        {
        public:
            InvalidCodeException(int code);
        };

        // statics
        static TTarget* Unserialize(std::istream &stream);
        static bool RegisterFactoryMethod(int type, Instantinator method);

    protected:

        // seriallization
        virtual void DoSerialize(std::ostream &stream) const = 0;
        virtual void DoUnserialize(std::istream &stream) = 0;

    private:

        // unserialization related factory
        typedef std::map<int, Instantinator> FactoryRegister;
        static FactoryRegister& GetFactoryRegister();
    };
}

#include "Message.impl.h"

#endif	/* _MESSAGE_H */

