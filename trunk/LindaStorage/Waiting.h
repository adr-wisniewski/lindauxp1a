/* 
 * File:   Waiting.h
 * Author: Pawel
 *
 * Created on 20 grudzień 2009, 20:42
 */

#ifndef _WAITING_H
#define	_WAITING_H

struct Waiting
{
    int id;
    Linda::Query query;
    bool input;
    Waiting(int p, Linda::Query q, bool i): id(p), query(q), input(i)
    {
        
    }
};

#endif	/* _WAITING_H */

