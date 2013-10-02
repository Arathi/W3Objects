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
        record.parser(line);
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

void SylkFile::save(string filename, bool compress)
{
    //B;X35;Y274;D0
    //C;X1;Y1;K"itemID"
    clog<<"开始保存slk到"<<filename<<endl;
    string file_text="", temp;
    string eol=compress?"\r":"\n";
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
        x0 = ( y%2==0 && compress ) ? _x : 1;
        dx = ( y%2==0 && compress ) ? -1 : 1;
        //clog<<"x0="<<x0<<", "
            //<<"dx="<<dx<<endl;
        x = x0;
        //for (x=1; x<=_x; x+=dx)
        while (true)
        {
            if (!compress)
            {
                if (x>_x) break;
            }
            else
            {
                if (x<=0) break;
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

void SylkFile::gen_indexs(string field)
{
    //创建索引（如果没有指定名字，则创建entry字段的索引）
}
