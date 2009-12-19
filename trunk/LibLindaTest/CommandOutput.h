/* 
 * File:   CommandOutput.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 20:30
 */

#ifndef _COMMANDOUTPUT_H
#define	_COMMANDOUTPUT_H

#include "MessageCommand.h"
#include "MessageUnserializable.h"

#include <Tuple.h>

namespace Linda
{
    namespace Test
    {
        class CommandOutput;

        typedef MessageUnserializable<CommandOutput, MessageCommand, 6>
            UnserializableCommandOutput;

        class CommandOutput :
            public MessageCommand,
            private UnserializableCommandOutput
        {
        public:
            virtual void DoSerialize(std::ostream &stream);
            virtual Message* DoUnserialize(std::istream &stream);

            virtual int GetCode() const;
            virtual void Process(ProcessorCommand *processor);

            const Tuple& GivenTuple() const;
            void GivenTuple(const Tuple& value);

        protected:
            Tuple mGivenTuple;
        };
    }
}

#endif	/* _COMMANDOUTPUT_H */

