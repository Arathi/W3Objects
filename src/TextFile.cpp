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
            node.init(objId);
        }
        else
        {
            //键值对
            node.add_param(line);
        }
    }
}

void TextFile::add_profile(ProfileNode node)
{
    _profile_nodes.push_back(node);

}
