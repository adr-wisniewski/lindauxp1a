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

#include <Id.h>
#include <IdTest.h>


int main(int argc, char** argv) {

    try
    {
        Linda::Test::NodeTester tester;
        return tester.Run() ? EXIT_SUCCESS : EXIT_FAILURE;
    }
    catch(std::exception &e)
    {
        Linda::debug_print(boost::str(
                boost::format("Fatal exception in tester %1%: %2%\n") % getpid() % e.what()
        ));

        return EXIT_FAILURE;
    }
}