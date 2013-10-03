#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "ProfileNode.h"

using namespace std;

class TextFile
{
public:
    TextFile();
    virtual ~TextFile();

    void add_profile(ProfileNode profile);
protected:
private:
    vector<ProfileNode> _profile_nodes;
    map<int, int> _id_profile_map;
};

#endif // TEXTFILE_H
