#ifndef PROFILENODE_H
#define PROFILENODE_H

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include "Utils.h"
#include "ProfileParam.h"
using namespace std;

class ProfileNode
{
public:
    ProfileNode();
    virtual ~ProfileNode();

    void init(string id);

    void set_object_id(string id);
    int get_object_id();

    //void add_param(string key, string value);
    void add_param(ProfileParam param);
    void add_param(string param_str);
    string get_param(string key, int index);
    vector< ProfileParam > get_params();
    vector<string> split_value(string value_line);
    void clear();
    bool merge(ProfileNode other);

    string to_string(string eol="\n");
protected:
private:
    int _object_id;
    string _object_id_string;
    vector< ProfileParam > _params;
    map<string, int> _param_index_map;
};

#endif // PROFILENODE_H
