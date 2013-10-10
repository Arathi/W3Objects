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
    void save(ifstream &fin);
protected:
private:
    int _object_amount;
    vector<ObjectDefinition> _objects;
};

#endif // OBJECTTABLE_H
