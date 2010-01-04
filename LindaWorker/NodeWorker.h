/* 
 * File:   NodeWorker.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 15:28
 */

#ifndef _NODEWORKER_H
#define	_NODEWORKER_H

#include <ProcessorCommand.h>
#include <MessageCommand.h>
#include <MessageResult.h>

#include <Linda.h>

namespace Linda
{
    namespace Test
    {
        class NodeWorker : public ProcessorCommand
        {
        public:
            NodeWorker(int commandRead, int resultWrite, int requestWrite, int responseRead);
            void Run();

            virtual void Process(CommandCreate &c);
            virtual void Process(CommandKill &c);
            virtual void Process(CommandStat &c);
            virtual void Process(CommandOutput &c);
            virtual void Process(CommandInput &c);
            virtual void Process(CommandRead &c);

        private:
            Linda          mLinda;
            PipeCommand    mPipeCommand;
            PipeResult     mPipeResult;
        };
    }
}

#endif	/* _NODEWORKER_H */

