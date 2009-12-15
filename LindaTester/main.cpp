/* 
 * File:   main.cpp
 * Author: adrian
 *
 * Created on 12 grudzień 2009, 22:06
 */

#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <sys/types.h>
#include <unistd.h>

#include <Pipes.h>

using namespace std;
using namespace Linda;
using namespace Linda::Ex;


/*
 * 
 */
int main(int argc, char** argv) {

    // create pipes
    CommandPipe commandPipe;
    ResultPipe  resultPipe;

    // initialize storage
    switch(fork())
    {
        // error
        case -1:
            perror("Tester process");
            return EXIT_FAILURE;

        // child
        case 0:
            commandPipe.CloseEnd(Pipe::WriteEnd);
            resultPipe.CloseEnd(Pipe::ReadEnd);
            execl('lindastorage', 
                    'lindastorage',
                    string(commandPipe.GetEnd(Pipe::ReadEnd)).c_str(),
                    string(resultPipe.GetEnd(Pipe::WriteEnd)).c_str(),
                    );
            return EXIT_FAILURE;

        // parent
        default:
            commandPipe.CloseEnd(Pipe::ReadEnd);
            resultPipe.CloseEnd(Pipe::WriteEnd);
    }

    // read input and process commands
    string input;
    Command *c;

    while(!getline(cin, input).eof())
    {
        try
        {
            c = Command.FromString(input);
        }
        catch(Command::InvalidException &e)
        {

        }

        // dispatch command
        commandPipe.Write(*c);

        // clean up
        delete c;
    }

    // wait for storage process to finish
    commandPipe.CloseEnd(Pipe::WriteEnd);

    // hooray!
    return EXIT_SUCCESS;
}
