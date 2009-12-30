/* 
 * File:   Operation.h
 * Author: adrian
 *
 * Created on 30 grudzień 2009, 19:43
 */

#ifndef _OPERATION_H
#define	_OPERATION_H

namespace Linda
{
    enum Operation
    {
        OperationEqual,
        OperationNotEqual,
        OperationLess,
        OperationEqualLess,
        OperationGreater,
        OperationEqualGreater,
        OperationAny
    };
}

#endif	/* _OPERATION_H */

