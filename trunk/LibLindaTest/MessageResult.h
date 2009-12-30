/* 
 * File:   MessageResult.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 20:25
 */

#ifndef _MESSAGERESULT_H
#define	_MESSAGERESULT_H

#include <Message.h>
#include <Serializable.h>
#include <Pipe.h>

namespace Linda
{
    namespace Test
    {
        class ProcessorResult;

        class MessageResult : 
            public Message<ProcessorResult>,
            public Serializable<MessageResult>
        {
        public:

            enum StatusCode
            {
                Status_Ok = 0,
                Status_Fail,
                Status_WorkerAlreadyExists,
                Status_WorkerDoesntExists,

                Status_MinCode = Status_Ok,
                Status_MaxCode = Status_WorkerDoesntExists
            };

            MessageResult();
            MessageResult(int ordinal, StatusCode status);

            int Ordinal() const;
            void Ordinal(int value);

            StatusCode Status() const;
            void Status(StatusCode value);

        protected:
            virtual void DoSerialize(std::ostream &stream) const;
            virtual void DoUnserialize(std::istream &stream);

            int mOrdinal;
            StatusCode mStatus;
        };


        typedef Pipe<MessageResult> PipeResult;
    }
}

#endif	/* _MESSAGERESULT_H */

