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
    _id.put_id(fout); //���ID
    fout.write((char *)&_type, 4); //�������
    //�����ѡ
    if (useOptionalInts)
    {
        fout.write((char*)&_level, 4); //level
        fout.write((char*)&_data_ptr, 4); //����ָ��
    }
    _value.put_value(fout);//���ֵ
    fout.write((char*)&_end, 4);//���������
}
