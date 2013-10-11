#include "ObjectIdentity.h"

ObjectIdentity::ObjectIdentity()
{
    //ctor
}

ObjectIdentity::~ObjectIdentity()
{
    //dtor
}

int ObjectIdentity::get_code()
{
    return _code;
}

string ObjectIdentity::get_id()
{
    return _id;
}

void ObjectIdentity::clear()
{
    _id="";
    _code=0;
}

void ObjectIdentity::set_id(const char *id)
{
    int i;
    _id="";
    if (strlen(id)==4)
    {
        _id=id;
    }
    else
    {
        for (i=0; i<4; i++)
        {
            _id+=id[i];
        }
    }

    _code = convertInt(id, true);
}

void ObjectIdentity::set_id(ifstream &fin)
{
    char id[5];
    fin.read(id, 4);
    id[4] = '\0';
    set_id(id);
}

void ObjectIdentity::put_id(ofstream &fout)
{
    int reversed_code = reverseEndian(_code);
    fout.write((char *)&reversed_code, 4);
}
