/* 
 * File:   UnserilizableMessage.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 20:04
 */

#ifndef _MESSAGEUNSERIALIZABLE_H
#define	_MESSAGEUNSERIALIZABLE_H

namespace Linda
{
     /**
     * CRTP patter for automatic registering registering commands in factory
     */
    template<class TMessage, class TBase, int TCode>
    class MessageUnserializable
    {
    public:

        static TMessage* Create()
        {
            return new TMessage();
        }

        static int GetCode()
        {
            return TCode;
        }

    private:
        static bool IsRegistered;
    };

    template<class TMessage, class TBase, int TCode>
    bool MessageUnserializable<TMessage, TBase, TCode>::IsRegistered =
        TBase::RegisterFactoryMethod(
            TCode,
            MessageUnserializable<TMessage, TBase, TCode>::Create
        );
}

#endif	/* _MESSAGEUNSERIALIZABLE_H */

