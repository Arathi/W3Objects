#include "SylkFile.h"

SylkFile::SylkFile()
{
    //ctor
}

SylkFile::SylkFile(string filename)
{
    load(filename);
}

SylkFile::~SylkFile()
{
    //dtor
}

/**
ID;PWXL;N;E
B;X35;Y274;D0
C;X1;Y1;K"itemID"
E
*/

void split(string line)
{

}

void SylkFile::load(string filename)
{
    ifstream fin( filename.c_str() );
    string line;
    while ( getline(fin, line) )
    {
        //
    }
}

void SylkFile::initTable(int x, int y)
{
    int iy;
    _table.clear();
    _table.resize(y);
    for (iy=0; iy<y; iy++)
    {
        vector<int> table_row(x);
        //_table
    }

}

