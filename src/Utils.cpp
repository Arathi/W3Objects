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
