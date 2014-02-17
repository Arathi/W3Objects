#include "TextFile.h"

TextFile::TextFile()
{
    //0号占位
    ProfileNode nullnode;
    _profile_nodes.push_back(nullnode);
}

TextFile::~TextFile()
{
    //dtor
}

void TextFile::load(string filename)
{
    clog<<"Loading profile "<<filename<<" ..."<<endl;
    //TODO 小心前后导空格、空行和注释行
    ifstream fin(filename.c_str());
    string line, eol;
    eol = getEndOfLine("");
    ProfileNode node;
    while ( getline(fin, line) )
    {
        if (line.length()==6 && line[0]=='[' && line[5]==']')
        {
            //ID，建立新的
            add_profile(node);
            string objId=line.substr(1,4);
            clog<<"获取到新ID: \'"<<objId<<"\'"<<endl;
            node.init(objId);
        }
        else
        {
            //键值对
            node.add_param(line);
        }
    }
    //读取到文件结束，插入最后一个Node
    add_profile(node);
}

void TextFile::save(string filename)
{
    ofstream fout(filename.c_str());
    string node_str;
    vector<ProfileNode>::iterator iter;
    for (iter=_profile_nodes.begin(); iter!=_profile_nodes.end(); iter++)
    {
        if (iter==_profile_nodes.begin()) continue;
        node_str=iter->to_string();
        fout<<node_str;
    }
}

void TextFile::add_profile(ProfileNode node)
{
    //首先在_id_profile_map中查找该ID
    int id=node.get_object_id();
    if (id==0) return;
    int index = _id_profile_map[id];
    if ( index ==0 )
    {
        _profile_nodes.push_back(node);
        index = _profile_nodes.size()-1;
        _id_profile_map[id]=index;
        clog<<"不存在"<<node.get_object_str()<<"("<<id<<")"<<", 新插入索引"<<index<<endl;
    }
    else
    {
        clog<<"已存在"<<node.get_object_str()<<", 索引号为"<<index<<endl;
        _profile_nodes.at(index).merge(node);
    }
}

string TextFile::get_profile(string id, string param, int index)
{
    ObjectIdentity objid;
    objid.set_id(id.c_str());
    int id_code = objid.get_code();
    map<int,int>::const_iterator iter;
    iter = _id_profile_map.find( id_code );
    if (iter != _id_profile_map.end() ) //找到
    {
        ProfileNode node = _profile_nodes[ _id_profile_map[ id_code ] ];
        return node.get_param( param, index );
    }
    return "";
}
