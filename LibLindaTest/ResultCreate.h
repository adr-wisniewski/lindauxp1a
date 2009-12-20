/* 
 * File:   ResultCreate.h
 * Author: adrian
 *
 * Created on 20 grudzień 2009, 11:46
 */

#ifndef _RESULTCREATE_H
#define	_RESULTCREATE_H

#include "MessageResult.h"
#include <MessageUnserializable.h>

namespace Linda
{
    namespace Test
    {
        class ResultCreate;

        typedef MessageUnserializable<ResultCreate, MessageResult, 3>
            UnserializableResultCreate;

        class ResultCreate :
            public MessageResult,
            private UnserializableResultCreate
        {
        public:
            ResultCreate();
            ResultCreate(int ordinal, bool status, int pid);

            virtual void DoSerialize(std::ostream &stream) const;
            virtual void DoUnserialize(std::istream &stream);

            virtual int GetCode() const;
            virtual void Process(ProcessorResult *processor);

            int Pid() const;
            void Pid(int value);

        protected:
            int mPid;
        };
    }
}

#endif	/* _RESULTCREATE_H */

