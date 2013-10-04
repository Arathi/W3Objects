#ifndef PROFILEPARAM_H
#define PROFILEPARAM_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class ProfileParam
{
public:
    ProfileParam();
    virtual ~ProfileParam();

    string get_name();
    string get_value(int index);
    bool parse(string values);
protected:
private:
    string _name;
    vector<string> _value_list;
};

#endif // PROFILEPARAM_H
