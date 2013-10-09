#include "ObjectTable.h"

ObjectTable::ObjectTable()
{
    //ctor
}

ObjectTable::~ObjectTable()
{
    //dtor
}

void ObjectTable::load(ifstream &fin)
{
    clog<<"Load a object table"<<endl;
    char tmp[4];
    fin.read(tmp, 4);
    int index;
    _object_amount=convertInt(tmp);
    clog<<"Object Amount: "<< _object_amount <<endl;
    for (index=0; index<_object_amount; index++)
    {
        ObjectDefinition object;
        object.load(fin);
        _objects.push_back(object);
    }
}
