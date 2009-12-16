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

namespace Linda
{
    class Message
    {
    public:
        Message();
        virtual ~Message();

        virtual int GetCode() const = 0;


    protected:

        // seriallization
        virtual void DoSerialize(std::ostream &stream) = 0;
        virtual Message* DoUnserialize(std::istream &stream) = 0;
    };
}

#endif	/* _MESSAGE_H */

