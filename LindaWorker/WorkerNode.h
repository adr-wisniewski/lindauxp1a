/* 
 * File:   WorkerNode.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 15:28
 */

#ifndef _WORKERNODE_H
#define	_WORKERNODE_H

#include <CommandProcessor.h>
#include <CommandMessage.h>
#include <ResultMessage.h>
#include <RequestMessage.h>
#include <ResponseMessage.h>

class WorkerNode : private Linda::Test::CommandVisitor
{
public:
    WorkerNode(int commandRead, int resultWrite, int requestWrite, int answerRead);
    void Run();

private:
    virtual void Process(Linda::Test::CreateCommand &c);
    virtual void Process(Linda::Test::KillCommand &c);
    virtual void Process(Linda::Test::StatCommand &c);
    virtual void Process(Linda::Test::OutputCommand &c);
    virtual void Process(Linda::Test::InputCommand &c);
    virtual void Process(Linda::Test::ReadCommand &c);

    Linda::Test::CommandPipe    commandPipe;
    Linda::Test::ResultPipe     resultPipe;
    Linda::RequestPipe          requestPipe;
    Linda::ResponsePipe         responsePipe;

};

#endif	/* _WORKERNODE_H */

