#ifndef PROFILENODE_H
#define PROFILENODE_H

#include <string>
#include <map>
#include <vector>
using namespace std;

class ProfileNode
{
public:
    ProfileNode();
    virtual ~ProfileNode();

    void add_param(string key, string value);
    string get_param(string key, int index);
    vector<string> split_value(string value_line);
protected:
private:
    int _object_id;
    string _object_id_string;
    vector< vector<string> > _values;
    map<string, int> _param_index_map;
};

#endif // PROFILENODE_H
