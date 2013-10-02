#include "SylkRecord.h"

SylkRecord::SylkRecord()
{
    //ctor
    _type=kSylkRecordTypeNull;
    _x_setFlag=false;
    _y_setFlag=false;
    _value_stringFlag=false;
    _x=0;
    _y=0;
    _value="";
}

SylkRecord::SylkRecord(string line)
{
    //ctor
}

SylkRecord::~SylkRecord()
{
    //dtor
}

void SylkRecord::set_x(int x)
{
    _x=x;
    _x_setFlag=true;
}

void SylkRecord::set_y(int y)
{
    _y=y;
    _y_setFlag=true;
}

int SylkRecord::get_x()
{
    return _x;
}

int SylkRecord::get_y()
{
    return _y;
}

void SylkRecord::set_value(string value)
{
    if (value[0]=='\"' && value[value.length()-1]=='\"')
    {
        _value_stringFlag=true;
        _value=value.substr( 1, value.length()-2 );
    }
    else
    {
        //_value_stringFlag=false;
        _value=value;
    }
}

string SylkRecord::get_value()
{
    return _value;
}

string SylkRecord::get_value_with_quote()
{
    if (_value_stringFlag)
    {
        return "\""+_value+"\"";
    }
    return _value;
}

bool SylkRecord::isset_x()
{
    return _x_setFlag;
}

bool SylkRecord::isset_y()
{
    return _y_setFlag;
}

int SylkRecord::get_type()
{
    return _type;
}

void SylkRecord::parser(string line)
{
    vector<string::size_type> linesplit;
    string::size_type last=0,semicolon_index=0;
    int line_length = line.length();
    //首先，插入第一个检查点
    if (line_length>0)
    {
        //clog<<"插入位置0"<<endl;
        linesplit.push_back(0);
    }
    else
    {
        last=string::npos;
    }
    while (last!=string::npos)
    {
        semicolon_index = line.find(';', last+1);
        //clog<<"查找\";\": ";
        if (semicolon_index != string::npos)
        {
            //clog<<"index="<<semicolon_index;
            linesplit.push_back( semicolon_index );
        }
        else
        {
            //clog<<"未找到";
        }
        //clog<<endl;
        last = semicolon_index;
    }
    linesplit.push_back(string::npos);
    //clog<<"偏移表中元素数量："<<linesplit.size()<<endl;
    vector<string::size_type>::iterator iter;
    string part="";
    int cul_index, next_index;
    int start_index, value_length;
    char type_ch;
    for (iter=linesplit.begin(); iter!=linesplit.end(); iter++)
    {
        if (iter==linesplit.begin())
        {
            //clog<<"跳过第一个"<<endl;
            cul_index=*iter;
            continue;
        }
        else
        {
            next_index=*iter;
        }
        if (cul_index==0)
        {
            type_ch=line[0];
            //clog<<"检测到类型为："<<type_ch<<endl;
            //首个字母，代表类型
            switch (type_ch)
            {
            case 'I':
            case 'i':
                //头部，没有意义
                _type=kSylkRecordTypeNull;
                break;
            case 'B':
            case 'b':
                //设置区，设置表大小
                _type=kSylkRecordTypeSetTable;
                break;
            case 'C':
            case 'c':
                //记录区，设定记录
                _type=kSylkRecordTypeValue;
                break;
            case 'E':
            case 'e':
                //结束符，标志文件结束
                _type=kSylkRecordTypeEnd;
                break;
            }
        }
        else if (cul_index>=0 && cul_index<line_length)
        {
            // +- cul_index=1;
            // |   +- next_index=5;
            //B;X35;Y274;D0
            type_ch = line[cul_index+1];
            //clog<<"位置: "<<cul_index<<" 类型："<<type_ch;
            start_index = cul_index+2;
            value_length = next_index-start_index;
            switch (type_ch)
            {
            case 'x':
            case 'X':
                part = line.substr( start_index, value_length );
                //clog <<" 值："<<part;
                set_x( str2int( part ) );
                break;
            case 'y':
            case 'Y':
                part = line.substr( start_index, value_length );
                set_y( str2int( part ) );
                break;
            case 'K':
            case 'k':
                part = line.substr( start_index );
                set_value( part );
                break;
            }
        }
        cul_index=next_index;
    }
}

void SylkRecord::copy_param(SylkRecord record)
{
    clog<<"SylkRecord::copy_param(SylkRecord) 未实现"<<endl;
    //_type=record.get_type();
    //set_x(record.get_x());
    //set_y(record.get_y());
    //set_value(record.get_value());
}

string SylkRecord::to_string()
{
    /**
    ID;PWXL;N;E
    B;X35;Y274;D0
    C;X1;Y1;K"itemID"
    E
    */
    stringstream ss;
    if (_type==kSylkRecordTypeSetTable)
    {
        ss<<"B;X"<<_x<<";Y"<<_y<<";D0";
    }
    else if (_type==kSylkRecordTypeValue)
    {
        ss<<"C;X"<<_x<<";Y"<<_y<<";K";
        //if ()
    }
    else
    {
        return "";
    }
    string ret;
    ss>>ret;
    return ret;
}

