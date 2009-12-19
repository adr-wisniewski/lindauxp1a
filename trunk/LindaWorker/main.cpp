/* 
 * File:   main.cpp
 * Author: adrian
 *
 * Created on 12 grudzień 2009, 22:07
 */

#include <exception>
#include <cstdlib>
#include <cstdio>
#include <boost/format.hpp>
#include <string>

#include <Exception.h>
#include "NodeWorker.h"

/*
 * 
 */
int main(int argc, char** argv) {

    try
    {
        if(argc != 5 || atoi(argv[1]) == 0 || atoi(argv[2]) == 0 || atoi(argv[3]) == 0 || atoi(argv[4]) == 0)
            throw Linda::Exception("Invalid program arguments");

        NodeWorker worker(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
        worker.Run();

        return EXIT_SUCCESS;
    }
    catch(std::exception &e)
    {
        std::string message = boost::str(
                boost::format("Fatal exception in worker %1%: %2%\n") % getpid() % e.what()
        );

        write(STDERR_FILENO, message.c_str(), message.length());
        fflush(stderr);

        return EXIT_FAILURE;
    }
}

