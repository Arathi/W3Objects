#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <sstream>
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

int str2int(string strvalue);
string int2str(int value);

int id2int(string idStr);
string int2id(int idInt);

string getEndOfLine(string context);

int convertInt(char* bytes, int size=4);
float convertReal(char* bytes, int size=4);
string convertString(char* bytes);

//double

#endif // UTILS_H_INCLUDED
