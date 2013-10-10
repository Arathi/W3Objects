#ifndef VALUE_H
#define VALUE_H

#include "Common.h"
#include "Utils.h"

class Value
{
public:
    Value();
    virtual ~Value();

    //void set_type(int type);
    void set_value(int type, ifstream &fin);
    void put_value(ofstream &fout);
protected:
private:
    int _type;

    int _integer;
    float _real;
    string _string;
};

#endif // VALUE_H
