/* 
 * File:   NodeTester.h
 * Author: adrian
 *
 * Created on 28 grudzień 2009, 14:47
 */

#ifndef _NODETESTER_H
#define	_NODETESTER_H

#include <ProcessorResult.h>

#include <map>
#include <unistd.h>

#include <MessageCommand.h>
#include <MessageResult.h>
#include "ParserCommand.h"

namespace Linda
{
    namespace Test
    {
        class NodeTester : public ProcessorResult
        {
        public:
            NodeTester();
            bool Run();

            virtual void Process(ResultBasic &r);
            virtual void Process(ResultStat &r);

        protected:
            typedef std::map<std::string, pid_t> PidMap;

            void InitializeStorage();
            bool ProcessInput();
            bool ProcessResult();
            void Finalize();

            void OutputResult(int ordinal, bool success, const char *message);

            PipeCommand     mPipeCommand;
            PipeResult      mPipeResult;
            ParserCommand   mParser;

            PidMap  mPids;
            int     mOrdinal;
            bool    mSuccess;
            pid_t   mStoragePid;
        };
    }
}

#endif	/* _NODETESTER_H */

