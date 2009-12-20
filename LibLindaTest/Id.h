/* 
 * File:   Id.h
 * Author: adrian
 *
 * Created on 20 grudzień 2009, 21:14
 */

#ifndef _ID_H
#define	_ID_H

#include <Serializable.h>

#define ASSIGN_ID(classname, id)                \
namespace Test                                  \
{                                               \
    class classname;                            \
}                                               \
                                                \
template<> struct ClassToId< Test::classname >  \
{                                               \
    static id_t Id()    {   return id;   }      \
}

namespace Linda
{
    ASSIGN_ID(CommandCreate,                                            200);
    ASSIGN_ID(CommandKill,                                              201);
    ASSIGN_ID(CommandStat,                                              202);
    ASSIGN_ID(CommandInput,                                             203);
    ASSIGN_ID(CommandRead,                                              204);
    ASSIGN_ID(CommandOutput,                                            205);

    ASSIGN_ID(ResultBasic,                                              210);
    ASSIGN_ID(ResultCreate,                                             211);
    ASSIGN_ID(ResultStat,                                               212);
}

#endif	/* _ID_H */

