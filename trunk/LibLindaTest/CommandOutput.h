/* 
 * File:   CommandOutput.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 20:30
 */

#ifndef _COMMANDOUTPUT_H
#define	_COMMANDOUTPUT_H

#include "MessageWorkerCommand.h"

#include <Tuple.h>

namespace Linda
{
    namespace Test
    {
        class CommandOutput :
            public MessageWorkerCommand,
            RegisterSerializable<CommandOutput, MessageCommand>
        {
        public:
            CommandOutput();
            CommandOutput(int ordinal, int workerId, const Tuple &tuple);

            virtual void Process(ProcessorCommand *processor);

            const Tuple& GivenTuple() const;
            void GivenTuple(const Tuple& value);

        protected:
            virtual id_t Id() const;
            virtual void DoSerialize(std::ostream &stream) const;
            virtual void DoUnserialize(std::istream &stream);

            Tuple mGivenTuple;
        };
    }
}

#endif	/* _COMMANDOUTPUT_H */

