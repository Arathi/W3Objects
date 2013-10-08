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
        //ch = idStr[i];
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

int convertInt(char* bytes, int size)
{
    int i, value=0;
    memcpy(&value, bytes, size);
    clog<<"Convert ";
    clog<<hex;
    for (i=0; i<size; i++)
    {
        clog<<setw(2)<<setfill('0')<<(int)(bytes[i])<<" ";
    }
    clog<<dec;
    clog<<" to "<<value<<endl;
    return value;
}

