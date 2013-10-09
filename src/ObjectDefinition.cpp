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
    char id[4];
    int index;
    fin.read( id, 4 );
    _original_id = convertId(id);
    fin.read( id, 4 );
    _new_id = convertId(id);
    fin.read( id, 4 );
    _modification_amount = convertInt(id);
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
