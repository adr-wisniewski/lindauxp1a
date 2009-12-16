/* 
 * File:   UnserilizableMessage.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 20:04
 */

#ifndef _UNSERIALIZABLEMESSAGE_H
#define	_UNSERIALIZABLEMESSAGE_H

namespace Linda
{
     /**
     * CRTP patter for automatic registering registering commands in factory
     */
    template<class TMessage, class TBase, int TCode>
    class UnserializableMessage
    {
        static TMessage* Create();
        static TMessage::code_t GetCode();

        static bool IsRegistered;
    };

    template<class TMessage, class TBase, int TCode>
    bool UnserializableMessage<TMessage>::IsRegistered
        = TBase::RegisterFactoryMethod(TCode, UnserializableMessage<TMessage>::Create);

    template<class TMessage, class TBase, int TCode>
    static TMessage* UnserializableMessage<TMessage>::Create()
    {
        return new TMessage();
    }

    template<class TMessage, class TBase, int TCode>
    static TMessage* UnserializableMessage<TMessage>::GetCode()
    {
        return TCode;
    }
}

#endif	/* _UNSERIALIZABLEMESSAGE_H */

