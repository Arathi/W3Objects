#ifndef VALUE_H
#define VALUE_H

#include "Common.h"

class Value
{
public:
    Value();
    virtual ~Value();
protected:
private:
    int _type;

    int _integer;
    float _real;
    string _string;
};

#endif // VALUE_H
