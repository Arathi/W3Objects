#include "Utils.h"

int str2int(string strvalue)
{
    int value=0;
    stringstream sstream;
    sstream<<strvalue;
    sstream>>value;
    clog<<strvalue<<" -> "<<value<<endl;
    return value;
}

int int2str(int value)
{

}
