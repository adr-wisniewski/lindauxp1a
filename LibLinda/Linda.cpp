/* 
 * File:   Linda.cpp
 * Author: adrian
 * 
 * Created on 19 grudzień 2009, 11:27
 */

#include "Linda.h"
#include "Exception.h"
#include "RequestRead.h"
#include "RequestInput.h"
#include "RequestOutput.h"
#include "ResponseInput.h"
#include "ResponseOutput.h"

namespace Linda
{

    Linda::Linda(int responseDescriptor, int requestDescriptor)
    :   mPipeResponse(responseDescriptor, PipeBase::EndClosed),
        mPipeRequest(PipeBase::EndClosed, requestDescriptor)
    {
    }

    bool Linda::Read(const Query &query, Tuple &tuple)
    {
        mPipeRequest.Write(RequestRead(query));
        return HandleResponseInput(tuple);
    }

    bool Linda::Input(const Query &query, Tuple &tuple)
    {
        mPipeRequest.Write(RequestInput(query));
        return HandleResponseInput(tuple);
    }

    bool Linda::Output(const Tuple &tuple)
    {
        mPipeRequest.Write(RequestOutput(tuple));
        return HandleResponseOutput();
    }

    bool Linda::HandleResponseInput(Tuple &tuple)
    {
        // should be smart_ptr
        MessageResponse* message = mPipeResponse.Read();
        ResponseInput* response = dynamic_cast<ResponseInput*>(message);

        if(response != 0 )
        {
            bool status = response->Status();

            if(status)
                tuple = response->GivenTuple();

            delete response;
            return status;
        }
        else
        {
            delete message;
            throw Exception("Linda::Linda::Read unexcepted message");
        }
    }

    bool Linda::HandleResponseOutput()
    {
        // should be smart_ptr
        MessageResponse* message = mPipeResponse.Read();
        ResponseOutput* response = dynamic_cast<ResponseOutput*>(message);

        if(response != 0 )
        {
            bool status = response->Status();

            delete response;
            return status;
        }
        else
        {
            delete message;
            throw Exception("Linda::Linda::Read unexcepted message");
        }
    }

}