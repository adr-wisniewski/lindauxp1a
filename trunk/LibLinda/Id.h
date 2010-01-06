/* 
 * File:   Id.h
 * Author: adrian
 *
 * Created on 20 grudzień 2009, 21:00
 */

#ifndef _ID_H
#define	_ID_H

#include "Serializable.h"
#include "Operation.h"

#define TPL(...) __VA_ARGS__


#define ASSIGN_ID(classname, id)            \
class classname;                            \
template<> struct ClassToId< classname >    \
{                                           \
    static id_t Id()    {   return id;   }  \
}

#define TPL_ASSIGN_ID(classname, id)        \
template<> struct ClassToId< classname >    \
{                                           \
    static id_t Id()    {   return id;   }  \
}

namespace Linda
{
    ASSIGN_ID(RequestInput,     100);
    ASSIGN_ID(RequestOutput,    102);

    ASSIGN_ID(ResponseInput,    110);
    ASSIGN_ID(ResponseOutput,   111);

    template<class T> class ConcreteTupleValue;
    TPL_ASSIGN_ID(TPL(ConcreteTupleValue<float>),        300);
    TPL_ASSIGN_ID(TPL(ConcreteTupleValue<int>),          301);
    TPL_ASSIGN_ID(TPL(ConcreteTupleValue<std::string>),  302);

    template<class T, Operation TOperation> class ConcreteQueryValue;
    //TPL_ASSIGN_ID(TPL(ConcreteQueryValue<float,OperationEqual>),        400);
    TPL_ASSIGN_ID(TPL(ConcreteQueryValue<float,OperationNotEqual>),     401);
    TPL_ASSIGN_ID(TPL(ConcreteQueryValue<float,OperationLess>),         402);
    TPL_ASSIGN_ID(TPL(ConcreteQueryValue<float,OperationEqualLess>),    403);
    TPL_ASSIGN_ID(TPL(ConcreteQueryValue<float,OperationGreater>),      404);
    TPL_ASSIGN_ID(TPL(ConcreteQueryValue<float,OperationEqualGreater>), 405);
    TPL_ASSIGN_ID(TPL(ConcreteQueryValue<float,OperationAny>),          406);

    TPL_ASSIGN_ID(TPL(ConcreteQueryValue<int,OperationEqual>),          410);
    TPL_ASSIGN_ID(TPL(ConcreteQueryValue<int,OperationNotEqual>),       411);
    TPL_ASSIGN_ID(TPL(ConcreteQueryValue<int,OperationLess>),           412);
    TPL_ASSIGN_ID(TPL(ConcreteQueryValue<int,OperationEqualLess>),      413);
    TPL_ASSIGN_ID(TPL(ConcreteQueryValue<int,OperationGreater>),        414);
    TPL_ASSIGN_ID(TPL(ConcreteQueryValue<int,OperationEqualGreater>),   415);
    TPL_ASSIGN_ID(TPL(ConcreteQueryValue<int,OperationAny>),            416);

    TPL_ASSIGN_ID(TPL(ConcreteQueryValue<std::string,OperationEqual>),          420);
    TPL_ASSIGN_ID(TPL(ConcreteQueryValue<std::string,OperationNotEqual>),       421);
    TPL_ASSIGN_ID(TPL(ConcreteQueryValue<std::string,OperationLess>),           422);
    TPL_ASSIGN_ID(TPL(ConcreteQueryValue<std::string,OperationEqualLess>),      423);
    TPL_ASSIGN_ID(TPL(ConcreteQueryValue<std::string,OperationGreater>),        424);
    TPL_ASSIGN_ID(TPL(ConcreteQueryValue<std::string,OperationEqualGreater>),   425);
    TPL_ASSIGN_ID(TPL(ConcreteQueryValue<std::string,OperationAny>),            426);
}

#endif	/* _ID_H */

