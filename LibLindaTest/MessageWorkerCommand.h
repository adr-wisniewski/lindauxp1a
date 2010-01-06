/* 
 * File:   MessageWorkerCommand.h
 * Author: adrian
 *
 * Created on 20 grudzień 2009, 11:35
 */

#ifndef _MESSAGEWORKERCOMMAND_H
#define	_MESSAGEWORKERCOMMAND_H

#include "MessageCommand.h"
#include <unistd.h>

namespace Linda
{
    namespace Test
    {
        class MessageWorkerCommand : public MessageCommand
        {
        public:
            MessageWorkerCommand();
            MessageWorkerCommand(int ordinal, int workerId);
            virtual ~MessageWorkerCommand(){};

            int WorkerId() const;
            void WorkerId(int value);

        protected:
            virtual void DoSerialize(Archive &stream) const;
            virtual void DoUnserialize(Archive &stream);

            int mWorkerId;
        };
    }
}



#endif	/* _MESSAGEWORKERCOMMAND_H */

