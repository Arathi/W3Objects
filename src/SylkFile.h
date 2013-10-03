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
    bool initTable(int x, int y);
    void save(string filename, bool compress=false);
    void gen_indexs(string field_name="");

protected:
private:
    void init();
    vector< vector<SylkRecord> > _table;
    //map<int, string> _y_id_map;
    map<string, int> _id_y_map;
    map<string, int> _field_x_map;

    int _x;
    int _y;
};

#endif // SYLKFILE_H
