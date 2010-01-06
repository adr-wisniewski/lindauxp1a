/* 
 * File:   Linda.cpp
 * Author: adrian
 * 
 * Created on 19 grudzień 2009, 11:27
 */

#include "Linda.h"
#include "Exception.h"
#include "RequestInput.h"
#include "RequestOutput.h"
#include "ResponseInput.h"
#include "ResponseOutput.h"
#include "Util.h"

namespace Linda
{

    Linda::Linda(int responseDescriptor, int requestDescriptor)
    :   mPipeResponse(responseDescriptor, PipeBase::EndClosed),
        mPipeRequest(PipeBase::EndClosed, requestDescriptor)
    {
    }

    bool Linda::Read(const Query &query, Tuple &tuple)
    {
        mPipeRequest.Write(RequestInput(getpid(), false, query));
        return HandleResponseInput(tuple);
    }

    bool Linda::Input(const Query &query, Tuple &tuple)
    {
        mPipeRequest.Write(RequestInput(getpid(), true, query));
        return HandleResponseInput(tuple);
    }

    bool Linda::Output(const Tuple &tuple)
    {
        mPipeRequest.Write(RequestOutput(getpid(), tuple));
        return HandleResponseOutput();
    }

    bool Linda::HandleResponseInput(Tuple &tuple)
    {
        // should be smart_ptr
        boost::shared_ptr<MessageResponse> message(mPipeResponse.Read());
        ResponseInput* response = dynamic_cast<ResponseInput*>(message.get());

        if(response != 0 )
        {
            bool status = response->Status();

            if(status)
                tuple = response->GivenTuple();

            return status;
        }
        else
        {
            throw Exception("Linda::Linda::Read unexcepted message");
        }
    }

    bool Linda::HandleResponseOutput()
    {
        // should be smart_ptr
        boost::shared_ptr<MessageResponse> message(mPipeResponse.Read());
        ResponseOutput* response = dynamic_cast<ResponseOutput*>(message.get());

        if(response != 0 )
        {
            return response->Status();
        }
        else
        {
            throw Exception("Linda::Linda::Read unexcepted message");
        }
    }

}