/* 
 * File:   StorageNode.h
 * Author: Pawel
 *
 * Created on 18 grudzień 2009, 20:08
 */

#ifndef _STORAGENODE_H
#define	_STORAGENODE_H

#include <list>

class StorageNode: private Linda::Test::ProcessorCommand, private Linda::ProcessorRequest
{
public:
    StorageNode(int commandRead, int answerRead);
    ~StorageNode();
    void Run();

private:
    virtual void Process(Linda::Test::CreateCommand &c);
    virtual void Process(Linda::Test::KillCommand &c);
    virtual void Process(Linda::Test::StatCommand &c);
    virtual void Process(Linda::Test::OutputCommand &c);
    virtual void Process(Linda::Test::InputCommand &c);
    virtual void Process(Linda::Test::ReadCommand &c);
    virtual void Process(Linda::RequestRead &r);
    virtual void Process(Linda::RequestInput &r);
    virtual void Process(Linda::RequestOutput &r);
    void Remove(int id);
    void RemoveWorker(int id);
    Worker* FindWorker(int id);

    Linda::Test::PipeCommand commandPipe;
    Linda::Test::PipeResult resultPipe;
    Linda::PipeRequest requestPipe;
    std::list<Worker*> workerList;
    std::list<Linda::Tuple> tuplesList;
    std::list<Waiting> waitingRequest;
};

#endif	/* _STORAGENODE_H */

