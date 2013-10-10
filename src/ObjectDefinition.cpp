#include "ObjectDefinition.h"

ObjectDefinition::ObjectDefinition()
{
    //ctor
}

ObjectDefinition::~ObjectDefinition()
{
    //dtor
}

void ObjectDefinition::load(ifstream &fin, char objectType)
{
    char tmpbytes[4];
    int index;
    _original_id.set_id(fin);
    _new_id.set_id(fin);
    fin.read( tmpbytes, 4 );
    _modification_amount = convertInt(tmpbytes);
    bool useOptionalInts=false;
    if (objectType=='a' || objectType=='d' || objectType=='q')
        useOptionalInts=true;
    for (index=0; index<_modification_amount; index++)
    {
        Modification mod;
        mod.load(fin, useOptionalInts);
        _modifications.push_back(mod);
    }
}
