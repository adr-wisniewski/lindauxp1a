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
            MessageWorkerCommand(int ordinal, pid_t pid);

            pid_t Pid() const;
            void Pid(pid_t value);

        protected:
            virtual void DoSerialize(std::ostream &stream) const;
            virtual void DoUnserialize(std::istream &stream);

            pid_t mPid;
        };
    }
}



#endif	/* _MESSAGEWORKERCOMMAND_H */

