/* 
 * File:   Command.h
 * Author: adrian
 *
 * Created on 12 grudzień 2009, 23:05
 */

#ifndef _MESSAGECOMMAND_H
#define	_MESSAGECOMMAND_H

#include <Message.h>
#include <Serializable.h>
#include <Pipe.h>

namespace Linda
{
    namespace Test
    {
        class ProcessorCommand;

        class MessageCommand : 
            public Message<ProcessorCommand>,
            public Serializable<MessageCommand>
        {
        public:
            MessageCommand();
            MessageCommand(int ordinal);
            virtual ~MessageCommand();

            int Ordinal() const;
            void Ordinal(int value);

            virtual void Process(ProcessorCommand *processor) = 0;

        protected:
            virtual void DoSerialize(Archive &stream) const;
            virtual void DoUnserialize(Archive &stream);

            int mOrdinal;
        };

        typedef Pipe<MessageCommand> PipeCommand;
    }
}

#endif	/* _MESSAGECOMMAND_H */

