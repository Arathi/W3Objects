#include "SylkFile.h"

SylkFile::SylkFile()
{
    init();
}

SylkFile::SylkFile(string filename)
{
    init();
    load(filename);
}

SylkFile::~SylkFile()
{
    //dtor
}

void SylkFile::init()
{
    _x=0;
    _y=0;
}

/**
ID;PWXL;N;E
B;X35;Y274;D0
C;X1;Y1;K"itemID"
E
*/

void SylkFile::load(string filename)
{
    ifstream fin( filename.c_str() );
    string line;
    int last_x=1, last_y=1, cul_x, cul_y;
    bool eof=false;
    while ( getline(fin, line) )
    {
        SylkRecord record;
        record.parse(line);
        cul_x=record.get_x();
        cul_y=record.get_y();
        int type=record.get_type();

        switch (type)
        {
        case kSylkRecordTypeNull:
            //不做任何操作
            clog<<"读取到无效记录"<<endl;
            break;
        case kSylkRecordTypeSetTable:
            //初始化表
            clog<<"正在初始化表："<<cul_x<<"*"<<cul_y<<endl;
            initTable(cul_x, cul_y);
            break;
        case kSylkRecordTypeValue:
            if (cul_x==0) cul_x=last_x;
            if (cul_y==0) cul_y=last_y;
            //clog<<"("<<cul_x<<","<<cul_y<<") = "<<record.get_value()<<endl;
            _table[cul_x][cul_y]=record;
            last_x=cul_x;
            last_y=cul_y;
            break;
        case kSylkRecordTypeEnd:
            eof = true;
            break;
        }

        if (eof)
        {
            break;
        }
    }

    gen_indexs();
}

bool SylkFile::initTable(int x, int y)
{
    //clog << "x=" << x << endl;
    //clog << "y=" << y << endl;
    _table.clear();
    if (x==0 || y==0) return false;
    _x = x;
    _y = y;
    _table.resize( x+1, vector<SylkRecord>(y+1) );
    return true;
}

void SylkFile::save(string filename)
{
    //B;X35;Y274;D0
    //C;X1;Y1;K"itemID"
    clog<<"开始保存slk到"<<filename<<endl;
    string file_text="", temp;
    string eol=_compress?"\r":"\n";
    int x, y, dx, x0, lastx=0, lasty=0;
    temp = "ID;PWXL;N;E"+eol;
    file_text += temp;
    temp = "B;";
    temp += "X"+int2str(_x)+";";
    temp += "Y"+int2str(_y)+";";
    temp += "D0"+eol;
    file_text += temp;
    //循环将记录值写入
    for (y=1; y<=_y; y++)
    {
        x0 = ( y%2==0 && _compress ) ? _x : 1;
        dx = ( y%2==0 && _compress ) ? -1 : 1;
        //clog<<"x0="<<x0<<", "
            //<<"dx="<<dx<<endl;
        x = x0;
        while (true)
        {
            if ( y%2==0 && _compress )
            {
                if (x<=0) break;
            }
            else
            {
                if (x>_x) break;
            }
            //clog<<"正在输出("<<x<<","<<y<<")"<<endl;
            SylkRecord record = _table.at(x).at(y);
            if (record.get_type()==kSylkRecordTypeValue)
            {
                temp = "C;";
                if (x!=lastx) temp += "X"+int2str(x)+";";
                if (y!=lasty) temp += "Y"+int2str(y)+";";
                temp += "K"+record.get_value_with_quote()+eol;
                file_text += temp;
                lastx=x;
                lasty=y;
            }
            x+=dx;
        }
    }
    file_text+="E"+eol;

    ofstream fout( filename.c_str() );
    fout<<file_text;
}

int SylkFile::get_field_order(string field_name)
{
    if (_field_x_map.size()==0) gen_indexs();
    int x = 0;
    x = _field_x_map[field_name];
    return x;
}

int SylkFile::get_id_order(string id)
{
    if (_id_y_map.size()==0) gen_indexs();
    int y = 0;
    y = _id_y_map[id];
    return y;
}

void SylkFile::gen_indexs(string field)
{
    //首先创建字段名与列号的索引
    clog<<"正在生成索引..."<<endl;
    int x, y;
    string field_name, id;
    y = 1;
    if (_field_x_map.size()==0)
    {
        for (x=1; x<=_x; x++)
        {
            SylkRecord record = _table[x][y];
            if (record.get_type()!=kSylkRecordTypeValue)
            {
                continue;
            }
            field_name = record.get_value();
            _field_x_map[field_name] = x;
        }
    }

    //创建ID（一般是第一个字段）索引
    x = 1;
    if (_id_y_map.size()==0)
    {
        for (y=2; y<=_y; y++)
        {
            SylkRecord record = _table[x][y];
            if (record.get_type()!=kSylkRecordTypeValue)
            {
                continue;
            }
            id = record.get_value();
            _id_y_map[id] = y;
        }
    }
}

void SylkFile::setTableData(int x, int y, string value)
{
    _table[x][y].set_value(value);
}

string SylkFile::getTableData(int x, int y)
{
    return _table[x][y].get_value();
}

int SylkFile::get_x()
{
    return _x;
}

int SylkFile::get_y()
{
    return _y;
}

