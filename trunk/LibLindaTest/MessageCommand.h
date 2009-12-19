/* 
 * File:   Command.h
 * Author: adrian
 *
 * Created on 12 grudzień 2009, 23:05
 */

#ifndef _MESSAGECOMMAND_H
#define	_MESSAGECOMMAND_H

#include <Message.h>
#include <Pipe.h>

namespace Linda
{
    namespace Test
    {
        class ProcessorCommand;

        struct Command_tag {};

        class MessageCommand : Message<Command_tag>
        {
        public:
            virtual void DoSerialize(std::ostream &stream);
            virtual Message* DoUnserialize(std::istream &stream);

            int Ordinal() const;
            void Ordinal(int value);

            virtual void Process(ProcessorCommand *processor) = 0;

        protected:
            int mOrdinal;
        };

        typedef Pipe<MessageCommand> PipeCommand;
    }
}

#endif	/* _MESSAGECOMMAND_H */
