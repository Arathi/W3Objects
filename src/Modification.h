#ifndef MODIFICATION_H
#define MODIFICATION_H

#include "Common.h"
#include "Value.h"

class Modification
{
public:
    Modification();
    virtual ~Modification();

    void load(ifstream &fin, bool useOptionalInts=false);
    void save(ofstream &fout, bool useOptionalInts=false);
protected:
private:
    int _id;
    string _id_str;

    int _type;
    int _level;
    int _data_ptr;
    Value _value;
    int _end;
};

#endif // MODIFICATION_H
