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
    if (fin.good()==false) return;
    _filename=filename;

    char tmp[4], type=filename[filename.length()-1];
    fin.read(tmp, 4);
    _version = convertInt(tmp);
    _original.load(fin, type, "original");
    _custom.load(fin, type, "custom");
}

void W3_File::save(string filename)
{
    ofstream fout(filename.c_str(), ios::binary | ios::out);
    fout.write((char *)&_version, 4);
    _original.save(fout);
    _custom.save(fout);
}
