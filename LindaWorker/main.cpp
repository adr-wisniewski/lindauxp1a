/* 
 * File:   main.cpp
 * Author: adrian
 *
 * Created on 12 grudzień 2009, 22:07
 */

#include <exception>
#include <boost/format.hpp>

#include <Exception.h>
#include <Util.h>
#include <boost/lexical_cast.hpp>

#include "NodeWorker.h"

/*
 * 
 */
int main(int argc, char** argv) {

    try
    {
        if(argc != 5)
            throw Linda::Exception("Invalid program arguments");

        int commandRead;
        int resultWrite;
        int requestWrite;
        int responseRead;

        try
        {
            commandRead     = boost::lexical_cast<int>(argv[1]);
            resultWrite     = boost::lexical_cast<int>(argv[2]);
            requestWrite    = boost::lexical_cast<int>(argv[3]);
            responseRead    = boost::lexical_cast<int>(argv[4]);
        }
        catch(boost::bad_lexical_cast)
        {
            throw Linda::Exception("Invalid program arguments");
        }


        Linda::Test::NodeWorker worker(commandRead, resultWrite, requestWrite, responseRead);
        worker.Run();

        return EXIT_SUCCESS;
    }
    catch(std::exception &e)
    {
        Linda::debug_print(boost::str(
                boost::format("Fatal exception in worker %1%: %2%\n") % getpid() % e.what()
        ));

        return EXIT_FAILURE;
    }
}

