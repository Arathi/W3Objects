#include "ObjectDefinition.h"

ObjectDefinition::ObjectDefinition()
{
    //ctor
}

ObjectDefinition::~ObjectDefinition()
{
    //dtor
}

void ObjectDefinition::load(ifstream &fin)
{
    char id[4];
    int index;
    fin.read( id, 4 );
    _original_id = convertInt(id);
    fin.read( id, 4 );
    _new_id = convertInt(id);
    fin.read( id, 4 );
    _modification_amount = convertInt(id);
    for (index=0; index<_modification_amount; index++)
    {
        Modification mod;
        mod.load(fin);
        _modifications.push_back(mod);
    }
}
