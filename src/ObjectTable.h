#ifndef OBJECTTABLE_H
#define OBJECTTABLE_H


class ObjectTable
{
public:
    ObjectTable();
    virtual ~ObjectTable();
protected:
private:
    int _object_amount;
    vector<ObjectDefinition> _objects;
};

#endif // OBJECTTABLE_H
