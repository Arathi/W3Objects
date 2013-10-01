#ifndef SYLKFILE_H
#define SYLKFILE_H

#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <fstream>

#include "SylkRecord.h"

using namespace std;

class SylkFile
{
public:
    SylkFile();
    SylkFile(string filename);
    virtual ~SylkFile();

    void load(string filename);
    void initTable(int x, int y);

protected:
private:
    vector< vector<SylkRecord> > _table;
    map<int,string> _index_id_map;
    map<string,int> _id_index_map;
};

#endif // SYLKFILE_H
