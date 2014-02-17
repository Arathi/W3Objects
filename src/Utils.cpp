#include "Utils.h"

int str2int(string strvalue)
{
    int value=0;
    stringstream sstream;
    sstream<<strvalue;
    sstream>>value;
    //clog<<" "<<strvalue<<" -> "<<value<<endl;
    return value;
}

string int2str(int value)
{
    string ret="";
    stringstream sstream;
    sstream<<value;
    sstream>>ret;
    return ret;
}

int id2int(string idStr)
{
    int idInt=0, i;
    char ch;
    if (idStr.length()!=4) return 0;
    for (i=0; i<4; i++)
    {
        idInt<<=8;
        ch = idStr[i];
        if ( ( ch>='0' && ch<='9' ) ||
            ( ch>='A' && ch<='Z' ) ||
            ( ch>='a' && ch<='z' ) )
        {
            idInt |= ch;
        }
        else return 0;
    }
    return idInt;
}

string int2id(int idInt)
{
    string idStr="____";
    char ch=0;
    for (int i=0; i<4; i++)
    {
        ch = idInt & 0xff;
        idInt >>= 8;
        if ( ( ch>='0' && ch<='9' ) ||
            ( ch>='A' && ch<='Z' ) ||
            ( ch>='a' && ch<='z' ) )
        {
            idStr[3-i]=ch;
        }
        else return "";
    }
    return idStr;
}

string getEndOfLine(string context)
{
    return "\n";
}

int convertInt(const char* obytes, bool bigEndian)
{
    int i, value=0;
    const char *bytes;
    char lbytes[4];
    if (bigEndian)
    {
        for (i=0; i<4; i++)
        {
            lbytes[i]=obytes[3-i];
        }
        bytes=lbytes;
    }
    else
    {
        bytes=obytes;
    }
    memcpy(&value, bytes, 4);
    return value;
}

int reverseEndian(int origin)
{
    int i, reversed=0;
    char mod;
    for (i=0; i<4; i++)
    {
        mod = origin&0xFF;
        reversed <<= 8;
        reversed |= mod;
        origin >>= 8;
    }
    return reversed;
}

/*
int convertId(const char* bytes, int size)
{
    int i;
    char byte_reverse[4];
    for (i=0; i<4; i++)
    {
        byte_reverse[i]=bytes[3-i];
    }
    return convertInt(byte_reverse);
}
*/
float convertReal(const char* bytes, int size)
{
    float value=0;
    memcpy(&value, bytes, size);
    return value;
}

string convertString(const char* bytes)
{
    string value=bytes;
    return value;
}

string& lTrim(string &ss)
{
    //string::iterator p=find_if(ss.begin(),ss.end(),not1(ptr_fun(isspace)));
    string::iterator p;
    for (p=ss.begin(); p!=ss.end(); p++)
        if (!isspace(*p)) break;
    ss.erase(ss.begin(),p);
    return ss;
}

string& rTrim(string &ss)
{
    //string::reverse_iterator  p=find_if(ss.rbegin(),ss.rend(),not1(ptr_fun(isspace)));
    string::reverse_iterator p;
    for (p=ss.rbegin(); p!=ss.rend(); p++)
        if (!isspace(*p)) break;
    ss.erase(p.base(),ss.end());
    return ss;
}

string& trim(string &st)
{
    lTrim(rTrim(st));
    return st;
}

vector<string> split(string str,string pattern)
{
    string::size_type pos;
    vector<string> result;
    str+=pattern;//扩展字符串以方便操作
    int size=str.size();
    for(int i=0; i<size; i++)
    {
        pos=str.find(pattern,i);
        if(pos<size)
        {
            string s=str.substr(i,pos-i);
            result.push_back(s);
            i=pos+pattern.size()-1;
        }
    }
    return result;
}
