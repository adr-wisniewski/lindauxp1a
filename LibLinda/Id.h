/* 
 * File:   Id.h
 * Author: adrian
 *
 * Created on 20 grudzień 2009, 21:00
 */

#ifndef _ID_H
#define	_ID_H

#include "Serializable.h"
#include "RequestInput.h"

#define TEMPL(...) __VA_ARGS__
#define ASSIGN_ID(classname, id)            \
class classname;                            \
template<> struct ClassToId< classname >    \
{                                           \
    static id_t Id()    {   return id;   }  \
}

namespace Linda
{
    ASSIGN_ID(RequestInput,                                             100);
    ASSIGN_ID(RequestRead,                                              101);
    ASSIGN_ID(RequestOutput,                                            102);

    ASSIGN_ID(ResponseInput,                                            110);
    ASSIGN_ID(ResponseOutput,                                           111);

    ASSIGN_ID(ConcreteTupleValue<float>,                                300);
    ASSIGN_ID(ConcreteTupleValue<int>,                                  301);
    ASSIGN_ID(ConcreteTupleValue<std::string>,                          302);

    ASSIGN_ID(TEMPL(ConcreteQueryValue<float,OperationEqual>),          400);
    ASSIGN_ID(TEMPL(ConcreteQueryValue<float,OperationNotEqual>),       401);
    ASSIGN_ID(TEMPL(ConcreteQueryValue<float,OperationLess>),           402);
    ASSIGN_ID(TEMPL(ConcreteQueryValue<float,OperationEqualLess>),      403);
    ASSIGN_ID(TEMPL(ConcreteQueryValue<float,OperationGreater>),        404);
    ASSIGN_ID(TEMPL(ConcreteQueryValue<float,OperationEqualGreater>),   405);
    ASSIGN_ID(TEMPL(ConcreteQueryValue<float,OperationAny>),            406);

    ASSIGN_ID(TEMPL(ConcreteQueryValue<int,OperationEqual>),            410);
    ASSIGN_ID(TEMPL(ConcreteQueryValue<int,OperationNotEqual>),         411);
    ASSIGN_ID(TEMPL(ConcreteQueryValue<int,OperationLess>),             412);
    ASSIGN_ID(TEMPL(ConcreteQueryValue<int,OperationEqualLess>),        413);
    ASSIGN_ID(TEMPL(ConcreteQueryValue<int,OperationGreater>),          414);
    ASSIGN_ID(TEMPL(ConcreteQueryValue<int,OperationEqualGreater>),     415);
    ASSIGN_ID(TEMPL(ConcreteQueryValue<int,OperationAny>),              416);

    ASSIGN_ID(TEMPL(ConcreteQueryValue<std::string,OperationEqual>),    420);
    ASSIGN_ID(TEMPL(ConcreteQueryValue<std::string,OperationNotEqual>), 421);
    ASSIGN_ID(TEMPL(ConcreteQueryValue<std::string,OperationLess>),     422);
    ASSIGN_ID(TEMPL(ConcreteQueryValue<std::string,OperationEqualLess>),423);
    ASSIGN_ID(TEMPL(ConcreteQueryValue<std::string,OperationGreater>),  424);
    ASSIGN_ID(TEMPL(ConcreteQueryValue<std::string,OperationEqualGreater>),425);
    ASSIGN_ID(TEMPL(ConcreteQueryValue<std::string,OperationAny>),      426);
}

#endif	/* _ID_H */

