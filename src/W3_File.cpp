#include "W3_File.h"

W3_File::W3_File()
{
    //ctor
}

W3_File::~W3_File()
{
    //dtor
}

void W3_File::load(string filename)
{
    ifstream fin(filename.c_str(), ios::binary | ios::in); //与slk和txt不同，w3*是二进制文件
    char id[4];
    fin.read(id, 4);
    _version = convertInt(id);
    clog<<"版本号"<<_version<<endl;
    //读取 _version
    _original.load(fin);
    _custom.load(fin);
}
