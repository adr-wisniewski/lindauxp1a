/* 
 * File:   CommandInput.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 20:30
 */

#ifndef _COMMANDINPUT_H
#define	_COMMANDINPUT_H

#include "MessageWorkerCommand.h"

#include <Query.h>

namespace Linda
{
    namespace Test
    {
        class CommandInput :
            public MessageWorkerCommand,
            private RegisterSerializable<CommandInput, MessageCommand>
        {
        public:
            CommandInput();
            CommandInput(int ordinal, pid_t pid, const Query &query);

            virtual void Process(ProcessorCommand *processor);

            const Query GivenQuery() const;
            void GivenQuery(const Query& query);

        protected:
            virtual id_t Id() const;
            virtual void DoSerialize(std::ostream &stream) const;
            virtual void DoUnserialize(std::istream &stream);

            Query mGivenQuery;
        };
    }
}

#endif	/* _COMMANDINPUT_H */

