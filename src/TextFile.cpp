#include "TextFile.h"

TextFile::TextFile()
{
    //0��ռλ
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
    //TODO С��ǰ�󵼿ո񡢿��к�ע����
    ifstream fin(filename.c_str());
    string line, eol;
    eol = getEndOfLine("");
    ProfileNode node;
    while ( getline(fin, line) )
    {
        if (line.length()==6 && line[0]=='[' && line[5]==']')
        {
            //ID�������µ�
            add_profile(node);
            string objId=line.substr(1,4);
            clog<<"��ȡ����ID: \'"<<objId<<"\'"<<endl;
            node.init(objId);
        }
        else
        {
            //��ֵ��
            node.add_param(line);
        }
    }
    //��ȡ���ļ��������������һ��Node
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
    //TODO �ϲ�����
    //������_id_profile_map�в��Ҹ�ID
    int id=node.get_object_id();
    if (id==0) return;
    int index = _id_profile_map[id];
    if ( index ==0 )
    {
        _profile_nodes.push_back(node);
        index = _profile_nodes.size()-1;
        _id_profile_map[id]=index;
        clog<<"������"<<node.get_object_str()<<"("<<id<<")"<<", �²�������"<<index<<endl;
    }
    else
    {
        clog<<"�Ѵ���"<<node.get_object_str()<<", ������Ϊ"<<index<<endl;
        _profile_nodes.at(index).merge(node);
    }
}
