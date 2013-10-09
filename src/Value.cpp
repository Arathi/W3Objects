#include "Value.h"

Value::Value()
{
    //ctor
}

Value::~Value()
{
    //dtor
}

void Value::set_value(int type, ifstream &fin)
{
    _type=type;
    char temp[4], ch;
    switch (type)
    {
    case 0: //Integer
        fin.read( temp, 4 );
        _integer = convertInt(temp);
        break;
    case 1: //Real
    case 2: //Unreal
        fin.read( temp, 4 );
        _real = convertReal(temp);
        break;
    case 3: //String
        _string = "";
        fin.read(&ch, 1);
        while (ch!=0)
        {
            _string=_string+ch;
            fin.read(&ch, 1);
        }
        break;
    }
}
