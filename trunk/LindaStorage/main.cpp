/* 
 * File:   main.cpp
 * Author: adrian
 *
 * Created on 12 grudzień 2009, 22:07
 */

#include <unistd.h>
#include <stdlib.h>
#include <exception>
#include <boost/lexical_cast.hpp>
#include <Exception.h>
#include <Util.h>


#include "StorageNode.h"

#include <Id.h>
#include <IdTest.h>
/*
 * 
 */
int main(int argc, char** argv) {

    try
    {
        if(argc != 3)
            throw Linda::Exception("Invalid program arguments");

        int commandRead;
        int resultWrite;

        try
        {
            commandRead     = boost::lexical_cast<int>(argv[1]);
            resultWrite     = boost::lexical_cast<int>(argv[2]);
        }
        catch(boost::bad_lexical_cast)
        {
            throw Linda::Exception("Invalid program arguments");
        }

        Linda::Test::StorageNode storage(commandRead, resultWrite);
        return storage.Run() ? EXIT_SUCCESS : EXIT_FAILURE;
    }
    catch (std::exception &e)
    {
        Linda::debug_print(
                boost::format("Fatal exception in storage %1%: %2%\n") % getpid() % e.what()
        );
        
        return EXIT_FAILURE;
    }
}

