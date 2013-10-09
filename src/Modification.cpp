#include "Modification.h"

Modification::Modification()
{
    //ctor
}

Modification::~Modification()
{
    //dtor
}

void Modification::load(ifstream &fin, bool useOptionalInts)
{
    char id[4];
    fin.read(id, 4);
    _id = convertInt(id);
    fin.read(id, 4);
    _type = convertInt(id);
    if (useOptionalInts)
    {
        fin.read(id, 4);
        _level=convertInt(id);
        fin.read(id, 4);
        _data_ptr=convertInt(id);
    }
    _value.set_value(_type, fin);
    fin.read(id, 4);
    _end = convertInt(id);
}
