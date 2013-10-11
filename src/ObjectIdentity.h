#ifndef OBJECTIDENTITY_H
#define OBJECTIDENTITY_H

#include "Common.h"
#include "Utils.h"

class ObjectIdentity
{
public:
    ObjectIdentity();
    virtual ~ObjectIdentity();

    int get_code();
    string get_id();

    void clear();
    void set_id(const char *id);
    //void set_id(string id);
    void set_id(ifstream &fin);
    void put_id(ofstream &fout);
protected:
private:
    int _code;
    string _id;
};

#endif // OBJECTIDENTITY_H
