#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <sstream>
#include <iostream>

using namespace std;

int str2int(string strvalue);
string int2str(int value);

int id2int(string idStr);
string int2id(int idInt);

string getEndOfLine(string context);

#endif // UTILS_H_INCLUDED
