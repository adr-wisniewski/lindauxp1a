/* 
 * File:   Worker.h
 * Author: Pawel
 *
 * Created on 18 grudzień 2009, 20:37
 */

#ifndef _WORKER_H
#define	_WORKER_H

class Worker
{
private:
    int id;
    Linda::Test::CommandPipe commandPipe;
    Linda::ResponsePipe responsePipe;

public:
    Worker(Linda::RequestPipe requestPipe,
        Linda::Test::ResultPipe resultPipe);
    ~Worker();
    int GetId();
    
};

#endif	/* _WORKER_H */

