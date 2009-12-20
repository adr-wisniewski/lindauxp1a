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
    Linda::Test::PipeCommand commandPipe;
    Linda::PipeResponse responsePipe;

public:
    Worker(Linda::PipeRequest requestPipe,
        Linda::Test::PipeResult resultPipe);
    ~Worker();
    const Linda::Test::PipeCommand& GetPipeCommand();
    const Linda::PipeResponse& GetPipeResponse();
    int GetId();
    
};

#endif	/* _WORKER_H */

