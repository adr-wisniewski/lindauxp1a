/* 
 * File:   MessageResult.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 20:25
 */

#ifndef _MESSAGERESULT_H
#define	_MESSAGERESULT_H

#include <Message.h>

namespace Linda
{
    namespace Test
    {
        class MessageResult;
        class ProcessorResult;

        struct Result_tag {};

        typedef MessageUnserializable<MessageResult, Message<Result_tag>, 1>
            MessageUnserializableResult;

        class MessageResult : 
            public Message<Result_tag>,
            private MessageUnserializableResult
        {
        public:
            MessageResult();
            MessageResult(int ordinal, bool status);

            virtual void DoSerialize(std::ostream &stream);
            virtual Message* DoUnserialize(std::istream &stream);

            virtual int GetCode() const;
            virtual void Process(ProcessorResult *processor);

            int Ordinal() const;
            void Ordinal(int value);

            bool Status() const;
            void Status(bool value);


        protected:
            int mOrdinal;
            bool mStatus;
        };


        typedef Pipe<MessageResult> PipeResult;
    }
}

#endif	/* _MESSAGERESULT_H */

