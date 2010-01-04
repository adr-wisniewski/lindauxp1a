/* 
 * File:   Message.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 17:00
 */

#ifndef _MESSAGE_H
#define	_MESSAGE_H

namespace Linda
{
    /**
     * Message interface
     */
    template<class TProcessor>
    class Message
    {
    public:
        virtual void Process(TProcessor* processor) = 0;
    };
}

#endif	/* _MESSAGE_H */

