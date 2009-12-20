#include <Worker.h>

Worker::Worker(Linda::RequestPipe requestPipe,
        Linda::Test::ResultPipe resultPipe)
{
    // initialize storage
    switch((id = fork())
    {
        // error
        case -1:
            throw Linda::Exception("Error: fork")
        // child
        case 0:
            commandPipe.CloseEnd(Pipe::WriteEnd);
            responsePipe.CloseEnd(Pipe::WriteEnd);
            execl('lindaworker',
                    'linda',
                    string(commandPipe.GetEnd(Pipe::ReadEnd)).c_str(),
                    string(resultPipe.GetEnd(Pipe::WriteEnd)).c_str(),
                    string(requestPipe.GetEnd(Pipe::WriteEnd)).c_str(),
                    string(responsePipe.GetEnd(Pipe::ReadEnd)).c_str()
                    );
            throw Exception("Error: execl");

        // parent
        default:
            commandPipe.CloseEnd(Pipe::ReadEnd);
            responsePipe.CloseEnd(Pipe::ReadEnd);
    }
}

Worker::~Worker()
{
    //zamkniecie potoku, usuniecie z oczekujacych krotek dotyczacych usuwajacego
    //zabicie procesu
}

int Worker::GetId()
{
    return id;
}

void Worker::Write(Linda::Test::CommandMessage cmd)
{
    commandPipe.Write(cmd);
}