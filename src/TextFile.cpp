#include "TextFile.h"

TextFile::TextFile()
{
    //ctor
}

TextFile::~TextFile()
{
    //dtor
}

void TextFile::load(string filename)
{
    //TODO С�Ŀ��к�ע��
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
    _profile_nodes.push_back(node);
}
