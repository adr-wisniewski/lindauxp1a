/* 
 * File:   main.cpp
 * Author: adrian
 *
 * Created on 12 grudzień 2009, 22:07
 */

#include <stdlib.h>
#include <exception>

/*
 * 
 */
int main(int argc, char** argv) {

    try
    {
        if(argc != 3 || atoi(argv[1] == 0 || atoi(argv[2] == 0)))
            throw SomeException("Invalid program arguments");

        StorageNode storage(atoi(argv[1]), atoi(argv[2]));
        storage.Run();

        return (EXIT_SUCCESS);
    }
    catch (std::Exception &e)
    {
        printerror("Fatal exception in storage: " + e.what());
        return EXIT_FAILURE;
    }
}

