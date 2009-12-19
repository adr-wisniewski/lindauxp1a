/* 
 * File:   MessageResult.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 20:25
 */

#ifndef _MESSAGERESULT_H
#define	_MESSAGERESULT_H

#include <Message.h>
#include <Pipe.h>

namespace Linda
{
    namespace Test
    {
        class ProcessorResult;

        class MessageResult : public Message<MessageResult, ProcessorResult>
        {
        public:
            typedef Message<MessageResult, ProcessorResult> Base;

            MessageResult();
            MessageResult(int ordinal, bool status);

            virtual void DoSerialize(std::ostream &stream) const;
            virtual void DoUnserialize(std::istream &stream);

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

