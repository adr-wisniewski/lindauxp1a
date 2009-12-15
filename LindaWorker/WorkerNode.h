/* 
 * File:   WorkerNode.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 15:28
 */

#ifndef _WORKERNODE_H
#define	_WORKERNODE_H

#include <CommandVisitor.h>
#include <CommandPipe.h>
#include <ResultPipe.h>
#include <RequstPipe.h>
#include <AnswerPipe.h>

class WorkerNode : private Linda::Test::CommandVisitor
{
public:
    WorkerNode(int commandRead, int resultWrite, int requestWrite, int answerRead);
    int Run();

private:

    virtual void Visit(Linda::Test::CommandCreate &c);
    virtual void Visit(Linda::Test::CommandKill &c);
    virtual void Visit(Linda::Test::CommandStat &c);
    virtual void Visit(Linda::Test::CommandOutput &c);
    virtual void Visit(Linda::Test::CommandInput &c);
    virtual void Visit(Linda::Test::CommandRead &c);

    Linda::Test::CommandPipe    commandPipe;
    Linda::Test::ResultPipe     resultPipe;
    Linda::RequestPipe          requestPipe;
    Linda::AnswerPipe           answerPipe;

};

#endif	/* _WORKERNODE_H */

