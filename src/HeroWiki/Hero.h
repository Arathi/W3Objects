#ifndef HERO_H
#define HERO_H

#include "../Common.h"

class Hero
{
public:
    Hero();
    virtual ~Hero();
protected:
    string _name;
    string _art;
    int _btn_x;
    int _btn_y;
private:
};

#endif // HERO_H
