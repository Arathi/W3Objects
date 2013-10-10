#include "ProfileParam.h"

ProfileParam::ProfileParam()
{
    //ctor
}

ProfileParam::~ProfileParam()
{
    //dtor
}

string ProfileParam::get_name()
{
    return _name;
}

string ProfileParam::get_value(int index)
{
    return _value_list.at(index);
}

bool ProfileParam::parse(string value_line)
{
    //vector<string> values;
    _value_list.clear();
    int sub_length;
    string value;
    string::size_type line_length=value_line.length(), i, startAt=0, endAt, quoteStartAt=string::npos, size;
    bool findEQ=false;
    //clog<<"LENGTH="<<line_length<<endl;
    for (i=0; i<line_length; i++)
    {
        //0123456789012
        //         +--- 9
        //         | +- 11
        //Buttonpos=0,2
        char ch=value_line[i];
        //clog<<i<<":\t"<<ch<<endl;
        if (findEQ==false && ch=='=')
        {
            findEQ=true;
            endAt=i;
            sub_length = endAt - startAt;
            value=value_line.substr(startAt, sub_length);
            startAt= endAt+1;
            _name = value;
        }
        if (findEQ==false) continue;
        if (ch=='\"') //���ţ��ֽ����
        {
            if (quoteStartAt==string::npos)
            {
                quoteStartAt=i;
            }
            else
            {
                quoteStartAt=string::npos;
            }
        }
        else if (ch==',') //�ָ���
        {
            if (quoteStartAt==string::npos)
            {
                //û������
                endAt = i;
                sub_length = endAt - startAt;
                value=value_line.substr(startAt, sub_length);
                _value_list.push_back( value );
                startAt = endAt + 1;
            }
            else
            {
                //�������ڣ�����
            }
        }
    }
    if (findEQ)
    {
        value=value_line.substr( startAt );
        _value_list.push_back( value );
    }
    size=_value_list.size();
    clog<<"ȡ��"<<size<<"��ֵ�����£�"<<endl;
    for (i=0; i<size; i++)
    {
        clog<<_name<<"["<<i<<"]="<<_value_list[i]<<endl;
    }
    return size>0;
}

string ProfileParam::to_string()
{
    string text="";
    text+=_name+"=";
    vector<string>::iterator iter;
    for ( iter=_value_list.begin(); iter!=_value_list.end(); iter++ )
    {
        if ( iter!=_value_list.begin() ) text+=",";
        text+=*iter;
    }
    return text;
}
