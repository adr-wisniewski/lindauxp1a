/* 
 * File:   Messages.h
 * Author: adrian
 *
 * Created on 12 grudzień 2009, 22:41
 */

#ifndef _MESSAGES_H
#define	_MESSAGES_H

namespace Linda
{
    namespace Message
    {
        struct Base
        {
            int mSize;
            int mType;
        };

        struct Command : Base
        {


        };
    }
}


#endif	/* _MESSAGES_H */

