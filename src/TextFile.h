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

    void load(string filename); //���ļ�����Profile
    void save(string filename); //����Profile���ļ�
    void add_profile(ProfileNode profile); //���һ��Profile�ڵ�
    string get_profile(string id, string param, int index=0); //��ȡָ��Profile������ֵ

protected:
private:
    string _filename;
    vector<ProfileNode> _profile_nodes;
    map<int, int> _id_profile_map;
};

#endif // TEXTFILE_H
