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
    if (fin.good()==false) return;
    _filename=filename;

    char id[4], type=filename[filename.length()-1];
    fin.read(id, 4);
    _version = convertInt(id);
    //clog<<"�汾��"<<_version<<endl;
    //��ȡ _version
    _original.load(fin, type, "original");
    _custom.load(fin, type, "custom");
}

void W3_File::save(string filename)
{
    ofstream fout(filename.c_str(), ios::binary | ios::out);
    //fout.write(_version, 4);
}
