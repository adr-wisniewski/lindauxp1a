/* 
 * File:   main.cpp
 * Author: adrian
 *
 * Created on 12 grudzień 2009, 22:06
 */

#include <exception>
#include <boost/format.hpp>

#include <Exception.h>
#include <Util.h>

#include "NodeTester.h"


int main(int argc, char** argv) {

    try
    {
        Linda::Test::NodeTester tester;
        tester.Run();

        return EXIT_SUCCESS;
    }
    catch(std::exception &e)
    {
        Linda::Test::debug_print(boost::str(
                boost::format("Fatal exception in worker %1%: %2%\n") % getpid() % e.what()
        ));

        return EXIT_FAILURE;
    }
}