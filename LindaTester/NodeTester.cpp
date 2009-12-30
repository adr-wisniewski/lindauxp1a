/* 
 * File:   NodeTester.cpp
 * Author: adrian
 * 
 * Created on 28 grudzień 2009, 14:47
 */

#include "NodeTester.h"

#include <unistd.h>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <cerrno>
#include <sstream>
#include <boost/lexical_cast.hpp>

#include <Exception.h>
#include <Util.h>

namespace Linda
{
namespace Test
{

    NodeTester::NodeTester()
    : mOrdinal(0), mSuccess(true)
    {
    }

    void NodeTester::Run()
    {
        // initialize storage node
        InitializeStorage();

        // create descriptor set for multiplexing
        fd_set set;
        int result = mPipeResult.GetEnd(PipeBase::EndRead);

        // flags for each source;
        bool isStdinOpened = true;
        bool isResultOpened = true;

        // read
        do
        {
            // initialize
            FD_ZERO (&set);

            if(isStdinOpened)
                FD_SET (STDIN_FILENO, &set);

            if(isResultOpened)
                FD_SET (result, &set);

            // pick descriptor
            TEMP_FAILURE_RETRY(select(FD_SETSIZE, &set, NULL, NULL, NULL));

            // process stdin
            if(isStdinOpened && FD_ISSET(STDIN_FILENO, &set))
                isStdinOpened = ProcessInput();

            // process results
            if(isResultOpened && FD_ISSET(result, &set))
                isResultOpened = ProcessResult();
        }
        while(isStdinOpened || isResultOpened);

        // cleanup
        Finalize();
    }

    void NodeTester::InitializeStorage()
    {
         // initialize storage
        switch(mStoragePid = fork())
        {
            // error
            case -1:
                throw Linda::Exception(errno, "NodeTester::InitializeStorage fork");

            // child
            case 0:
            {
                std::string command =
                    boost::lexical_cast<std::string>(mPipeCommand.GetEnd(PipeBase::EndRead));

                std::string result =
                    boost::lexical_cast<std::string>(mPipeResult.GetEnd(PipeBase::EndWrite));

                mPipeCommand.CloseEnd(PipeBase::EndWrite);
                mPipeResult.CloseEnd(PipeBase::EndRead);
                execl("lindastorage","lindastorage",command.c_str(),result.c_str(), (char*)0);
                throw Linda::Exception(errno, "NodeTester::InitializeStorage execl");
            }

            // parent
            default:
                mPipeCommand.CloseEnd(PipeBase::EndRead);
                mPipeResult.CloseEnd(PipeBase::EndWrite);
        }
    }

    bool NodeTester::ProcessInput()
    {
        // read input and dispatch commands
        std::string input;

        if(std::getline(std::cin, input).eof())
            return false;

        input = Linda::Test::trim(input);

        // igonre empty commands
        if(input != "")
        {
            try
            {
                // create command
                boost::shared_ptr<MessageCommand> command = mParser.Parse(input, ++mOrdinal);

                // send it to storage node
                mPipeCommand.Write(*command);
            }
            catch(ParserCommand::ParseException &e)
            {
                std::cout << "Error in input: " << e.what() << std::endl;
            }
        }

        return true;
    }

    bool NodeTester::ProcessResult()
    {
        boost::shared_ptr<MessageResult> message = mPipeResult.Read();
        message->Process(this);
    }

    /*virtual*/ void NodeTester::Process(ResultBasic &r)
    {
        if(r.Status() == MessageResult::Status_Ok)
        {
            OutputResult(r.Ordinal(), true, "OK");
            return;
        }

        // error happened
        mSuccess = false;
        
        // resolve status code into human readable message
        std::string message;
        switch(r.Status())
        {
            case MessageResult::Status_Fail:
                message = "Operation failed";
                break;

            case MessageResult::Status_WorkerAlreadyExists:
                message = "Worker already exists";
                break;

            case MessageResult::Status_WorkerDoesntExists:
                message = "Worker doesn't exist";
                break;
        }

        OutputResult(r.Ordinal(), false, message.c_str());
    }

    /*virtual*/ void NodeTester::Process(ResultStat &r)
    {
        std::ostringstream buffer;
        const ResultStat::StorageList &storage = r.Storage();
        const ResultStat::ReadList &reads = r.AwaitingReads();

        buffer << r.Ordinal() << "\tSTAT\n";

        buffer << "STORAGE\n";
        for(ResultStat::StorageList::const_iterator i = storage.begin(), e = storage.end(); i != e; ++i)
        {
            buffer << "\t" << *i << "\n";
        }

        buffer << "READS\n";
        for(ResultStat::ReadList::const_iterator i = reads.begin(), e = reads.end(); i != e; ++i)
        {
            buffer << "\t" << i->first << "\t" << i->second << "\n";
        }
    }

    void NodeTester::OutputResult(int ordinal, bool success, const char *message)
    {
        Linda::Test::debug_print(boost::str(boost::format("%1%\t%2%\t%3%\n")
            % ordinal
            % (success ? "PASS" : "FAIL")
            % message
        ));
    }

    void NodeTester::Finalize()
    {
        // wait for storage process to finish
        // TODO: waiting for storage to end reading exit code
    }

}
}

