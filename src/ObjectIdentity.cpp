#include "ObjectIdentity.h"

ObjectIdentity::ObjectIdentity()
{
    //ctor
}

ObjectIdentity::~ObjectIdentity()
{
    //dtor
}

void ObjectIdentity::set_id(char *id)
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

    _code = convertId(id);
}

void ObjectIdentity::set_id(ifstream &fin)
{
    char id[5];
    fin.read(id, 4);
    set_id(id);
}
