#include "ProfileNode.h"

ProfileNode::ProfileNode()
{
    //ctor
    _params.clear();
    _params.resize(1);//������һ��
}

ProfileNode::~ProfileNode()
{
    //dtor
}

void ProfileNode::add_param(ProfileParam param)
{
    string key = param.get_name();
    int index=_param_index_map[key];
    if (index==0)
    {
        _params.push_back(param);
        index = _params.size()-1;
        clog<<"�²���ID: "<<index<<endl;
        _param_index_map[key]=index;
    }
    else
    {
        _params.at(index)=param;
    }
}

string ProfileNode::get_param(string key, int value_index)
{
    int object_index=_param_index_map[key];
    if (object_index==0) return "";
    return _params.at(object_index).get_value(value_index);
}

void ProfileNode::set_object_id(string id)
{
    _object_id_string=id;
    _object_id=id2int(id);
}

int ProfileNode::get_object_id()
{
    return _object_id;
}

