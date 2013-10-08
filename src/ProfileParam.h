#ifndef PROFILEPARAM_H
#define PROFILEPARAM_H

#include "Common.h"

class ProfileParam
{
public:
    ProfileParam();
    virtual ~ProfileParam();

    string get_name();
    string get_value(int index);
    bool parse(string values);
    string to_string();
protected:
private:
    string _name;
    vector<string> _value_list;
};

#endif // PROFILEPARAM_H
