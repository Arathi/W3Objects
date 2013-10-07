#include "ProfileNode.h"

ProfileNode::ProfileNode()
{
    //ctor
    _params.clear();
    _params.resize(1);//保留第一个
}

ProfileNode::~ProfileNode()
{
    //dtor
}

void ProfileNode::add_param(ProfileParam param)
{
    //拒绝添加非法的Param
    if (param.get_name()=="") return;
    string key = param.get_name();
    int index=_param_index_map[key];
    if (index==0)
    {
        _params.push_back(param);
        index = _params.size()-1;
        clog<<"新插入ID: "<<index<<endl;
        _param_index_map[key]=index;
    }
    else
    {
        clog<<"覆盖已有ID："<<index<<endl;
        _params.at(index)=param;
    }
}

void ProfileNode::add_param(string param_str)
{
    ProfileParam param;
    param.parse(param_str);
    add_param(param);
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

void ProfileNode::clear()
{
    _object_id=0;
    _object_id_string="";
    _params.clear();
    _param_index_map.clear();
    ProfileParam tmp;
    _params.push_back(tmp);
}

void ProfileNode::init(string objId)
{
    clear();
    set_object_id(objId);
}

int ProfileNode::get_object_id()
{
    return _object_id;
}

string ProfileNode::to_string(string eol)
{
    string text="";
    text+="["+_object_id_string+"]"+eol;
    //vector<ProfileParam>::iterator iter;
    int i=0, size=_params.size();
    //for ( iter=_params.begin(); iter!=_params.end(); iter++ )
    for (i=1; i<size; i++)
    {
        //text+=iter->to_string()+eol;
        text+=_params[i].to_string()+eol;
    }
    return text;
}

vector<ProfileParam> ProfileNode::get_params()
{
    return _params;
}

bool ProfileNode::merge(ProfileNode other)
{
    //如果ID都不相符，拒绝合并
    if (other.get_object_id()!=_object_id)
        return false;
    vector<ProfileParam> other_params=other.get_params();
    int i, size=other_params.size();
    for (i=1; i<size; i++)
    {
        add_param( other_params[i] );
    }
    return true;
}

