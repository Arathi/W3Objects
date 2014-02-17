#ifndef __TAVERN_H__
#define __TAVERN_H__

#include "../Common.h"
#include "Hero.h"

class Tavern
{
public:
    Tavern();
    virtual ~Tavern();
protected:
private:
    string _name;
    Hero* _hero_list[4][3];
};

#endif // __TAVERN_H__
