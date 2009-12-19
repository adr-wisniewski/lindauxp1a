/* 
 * File:   CommandInput.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 20:30
 */

#ifndef _COMMANDINPUT_H
#define	_COMMANDINPUT_H

#include "MessageCommand.h"
#include "MessageUnserializable.h"

#include <Query.h>

namespace Linda
{
    namespace Test
    {
        class CommandInput;

        typedef MessageUnserializable<CommandInput, MessageCommand, 4>
            UnserializableCommandInput;

        class CommandInput :
            public MessageCommand,
            private UnserializableCommandInput
        {
        public:
            virtual void DoSerialize(std::ostream &stream);
            virtual Message* DoUnserialize(std::istream &stream);

            virtual int GetCode() const;
            virtual void Process(ProcessorCommand *processor);

            const Query GivenQuery() const;
            void GivenQuery(const Query& query);

        protected:
            Query mGivenQuery;
        };
    }
}

#endif	/* _COMMANDINPUT_H */

