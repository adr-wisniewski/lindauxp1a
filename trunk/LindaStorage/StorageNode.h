/* 
 * File:   StorageNode.h
 * Author: Pawel
 *
 * Created on 18 grudzień 2009, 20:08
 */

#ifndef _STORAGENODE_H
#define	_STORAGENODE_H

#include <list>
#include <unistd.h>
#include <boost/shared_ptr.hpp>

#include <ProcessorCommand.h>
#include <ProcessorRequest.h>
#include <MessageResult.h>
#include <MessageResponse.h>
#include <Query.h>
#include <AwaitingRead.h>

namespace Linda
{
    namespace Test
    {
        class StorageNode : public ProcessorCommand, public ProcessorRequest
        {
        public:
            StorageNode(int commandRead, int answerRead);
            
            bool Run();
            
            virtual void Process(CommandCreate &c);
            virtual void Process(CommandKill &c);
            virtual void Process(CommandStat &c);
            virtual void Process(CommandOutput &c);
            virtual void Process(CommandInput &c);
            virtual void Process(CommandRead &c);

            virtual void Process(RequestInput &r);
            virtual void Process(RequestOutput &r);
            
        protected:

            struct Worker
            {
                int             workerId;
                pid_t           workerPid;
                bool            active;
                PipeCommand     commandPipe;
                PipeResponse    responsePipe;
            };

            typedef std::list<boost::shared_ptr<Worker> >       WorkerList;
            typedef std::list<Tuple>                            TupleList;
            typedef std::list<AwaitingRead>                     ReadList;

            WorkerList::iterator GetWorkerByWorkerId(int workerId);
            WorkerList::iterator GetWorkerByWorkerPid(pid_t workerPid);
            bool ProcessCommand();
            bool ProcessRequest();
            void RelayCommand(MessageWorkerCommand &c);

            int mChildCount;
            bool mStatus;

            PipeCommand commandPipe;
            PipeResult  resultPipe;
            PipeRequest requestPipe;

            WorkerList  workerList;
            TupleList   tuplesList;
            ReadList    waitingRequest;
        };
    }
}

// TODO obsluga sigpipe

#endif	/* _STORAGENODE_H */

