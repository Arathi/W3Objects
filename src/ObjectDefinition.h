#ifndef OBJECTDEFINITION_H
#define OBJECTDEFINITION_H

#include "Common.h"
#include "Modification.h"
#include "ObjectIdentity.h"

class ObjectDefinition
{
public:
    ObjectDefinition();
    virtual ~ObjectDefinition();

    void load(ifstream &fin, char);
    void save(ofstream &fout);
protected:
private:
    ObjectIdentity _original_id;
    ObjectIdentity _new_id;
    int _modification_amount;
    vector<Modification> _modifications;
};

#endif // OBJECTDEFINITION_H
