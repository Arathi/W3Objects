#ifndef OBJECTTABLE_H
#define OBJECTTABLE_H

#include "Common.h"
#include "ObjectDefinition.h"

class ObjectTable
{
public:
    ObjectTable();
    virtual ~ObjectTable();

    void load(ifstream &fin, char objectType, string name="untitled");
    void save(ofstream &fout);
protected:
private:
    char _type;
    string _name;

    int _object_amount;
    vector<ObjectDefinition> _objects;
};

#endif // OBJECTTABLE_H
