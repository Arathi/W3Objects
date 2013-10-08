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
    ifstream fin(filename.c_str(), ios::binary | ios::in); //��slk��txt��ͬ��w3*�Ƕ������ļ�
    char id[4];
    fin.read(id, 4);
    _version = convertInt(id);
    clog<<"�汾��"<<_version<<endl;
    //��ȡ _version
    _original.load(fin);
    _custom.load(fin);
}
