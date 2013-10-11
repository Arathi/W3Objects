#include "ObjectTable.h"

ObjectTable::ObjectTable()
{
    //ctor
}

ObjectTable::~ObjectTable()
{
    //dtor
}

void ObjectTable::load(ifstream &fin, char objectType, string name)
{
    char tmp[4];
    int index;
    _name=name;
    _type=objectType;
    clog<<"Load \'"<<_type<<"\' table: "<<_name<<endl;
    fin.read(tmp, 4);
    _object_amount=convertInt(tmp);
    //clog<<"Object Amount: "<< _object_amount <<endl;
    for (index=0; index<_object_amount; index++)
    {
        ObjectDefinition object;
        object.load(fin, _type);
        _objects.push_back(object);
    }
}

void ObjectTable::save(ofstream &fout)
{
    int index;
    clog<<"Save \'"<<_type<<"\' table: "<<_name<<endl;
    _object_amount = _objects.size(); //���¼�����������
    fout.write((char*)&_object_amount, 4); //д����������
    for (index=0; index<_object_amount; index++)
    {
        _objects.at(index).save(fout, _type);
    }
}


