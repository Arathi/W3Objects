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
