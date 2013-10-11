#include "Modification.h"

Modification::Modification()
{
    //ctor
}

Modification::~Modification()
{
    //dtor
}

void Modification::load(ifstream &fin, bool useOptionalInts)
{
    char tmp[4];
    //fin.read(id, 4);
    //_id = convertInt(id);
    _id.set_id(fin);
    fin.read(tmp, 4);
    _type = convertInt(tmp);
    if (useOptionalInts)
    {
        fin.read(tmp, 4);
        _level=convertInt(tmp);
        fin.read(tmp, 4);
        _data_ptr=convertInt(tmp);
    }
    _value.set_value(_type, fin);
    fin.read(tmp, 4);
    _end = convertInt(tmp);
}

void Modification::save(ofstream &fout, bool useOptionalInts)
{
    //fout.write((char *));
    _id.put_id(fout); //输出ID
    fout.write((char *)&_type, 4); //输出类型
    //输出可选
    if (useOptionalInts)
    {
        fout.write((char*)&_level, 4); //level
        fout.write((char*)&_data_ptr, 4); //数据指针
    }
    _value.put_value(fout);//输出值
    fout.write((char*)&_end, 4);//输出结束符
}
