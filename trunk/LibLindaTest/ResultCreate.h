/* 
 * File:   ResultCreate.h
 * Author: adrian
 *
 * Created on 20 grudzień 2009, 11:46
 */

#ifndef _RESULTCREATE_H
#define	_RESULTCREATE_H

#include "MessageResult.h"
#include <unistd.h>

namespace Linda
{
    namespace Test
    {
        class ResultCreate :
            public MessageResult,
            RegisterSerializable<ResultCreate, MessageResult>
        {
        public:
            ResultCreate();
            ResultCreate(int ordinal, bool status, pid_t pid);

            virtual void Process(ProcessorResult *processor);

            pid_t Pid() const;
            void Pid(pid_t value);

        protected:
            virtual id_t Id() const;
            virtual void DoSerialize(std::ostream &stream) const;
            virtual void DoUnserialize(std::istream &stream);

            pid_t mPid;
        };
    }
}

#endif	/* _RESULTCREATE_H */

