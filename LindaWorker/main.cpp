/* 
 * File:   main.cpp
 * Author: adrian
 *
 * Created on 12 grudzień 2009, 22:07
 */

#include <exception>
#include <stdlib.h>


/*
 * 
 */
int main(int argc, char** argv) {

    try
    {
        if(argc != 5 || atoi(argv[1]) == 0 || atoi(argv[2]) == 0 || atoi(argv[3]) == 0 || atoi(argv[4]) == 0)
            throw SomeException("Invalid program arguments");

        NodeWorker worker(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
        worker.Run();

        return EXIT_SUCCESS;
    }
    catch(std::exception &e)
    {
        printerror("Fatal exception in worker " + getpid() + ": " + e.what());
        return EXIT_FAILURE;
    }
}

