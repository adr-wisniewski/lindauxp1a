/* 
 * File:   Id.h
 * Author: adrian
 *
 * Created on 20 grudzień 2009, 21:14
 */

#ifndef _IDTEST_H
#define	_IDTEST_H

#include <Serializable.h>

#define TEST_ASSIGN_ID(classname, id)           \
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
    TEST_ASSIGN_ID(CommandCreate,                                            200);
    TEST_ASSIGN_ID(CommandKill,                                              201);
    TEST_ASSIGN_ID(CommandStat,                                              202);
    TEST_ASSIGN_ID(CommandInput,                                             203);
    TEST_ASSIGN_ID(CommandRead,                                              204);
    TEST_ASSIGN_ID(CommandOutput,                                            205);

    TEST_ASSIGN_ID(ResultBasic,                                              210);
    TEST_ASSIGN_ID(ResultCreate,                                             211);
    TEST_ASSIGN_ID(ResultStat,                                               212);
}

#endif	/* _IDTEST_H */

