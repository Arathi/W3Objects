#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "ProfileNode.h"
#include "IW3File.h"

using namespace std;

class TextFile : public IW3File
{
public:
    TextFile();
    virtual ~TextFile();

    void load(string filename); //从文件载入Profile
    void save(string filename); //保存Profile到文件
    void add_profile(ProfileNode profile); //添加一个Profile节点
    string get_profile(string id, string param, int index=0); //获取指定Profile的属性值

protected:
private:
    string _filename;
    vector<ProfileNode> _profile_nodes;
    map<int, int> _id_profile_map;
};

#endif // TEXTFILE_H
