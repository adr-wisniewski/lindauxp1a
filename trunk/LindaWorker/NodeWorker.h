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

class NodeWorker : public Linda::Test::ProcessorCommand
{
public:
    NodeWorker(int commandRead, int resultWrite, int requestWrite, int answerRead);
    void Run();

    virtual void Process(Linda::Test::CommandCreate &c);
    virtual void Process(Linda::Test::CommandKill &c);
    virtual void Process(Linda::Test::CommandStat &c);
    virtual void Process(Linda::Test::CommandOutput &c);
    virtual void Process(Linda::Test::CommandInput &c);
    virtual void Process(Linda::Test::CommandRead &c);

private:
    Linda::Linda                mLinda;
    Linda::Test::PipeCommand    mPipeCommand;
    Linda::Test::PipeResult     mPipeResult;
};

#endif	/* _NODEWORKER_H */

