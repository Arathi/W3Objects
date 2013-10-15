#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <sstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>

using namespace std;

int str2int(string strvalue);
string int2str(int value);

int id2int(string idStr);
string int2id(int idInt);

string getEndOfLine(string context);

int convertInt(const char* bytes, bool bigEndian=false);
int reverseEndian(int origin);
//int convertId(const char* bytes, int size=4);
float convertReal(const char* bytes, int size=4);
string convertString(const char* bytes);

string& lTrim(string &ss);
string& rTrim(string &ss);
string& trim(string &st);

//double

#endif // UTILS_H_INCLUDED
