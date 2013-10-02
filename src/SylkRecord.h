#ifndef SYLKRECORD_H
#define SYLKRECORD_H

#include <vector>
#include <iostream>
#include "Utils.h"

using namespace std;

/**
ID;PWXL;N;E
B;X35;Y274;D0
C;X1;Y1;K"itemID"
E
*/

const int kSylkRecordTypeNull = 0;
const int kSylkRecordTypeSetTable = 1;
const int kSylkRecordTypeValue = 2;
const int kSylkRecordTypeEnd = 3;

class SylkRecord
{
public:
    SylkRecord();
    SylkRecord(string);
    virtual ~SylkRecord();

    int get_type();
    void set_x(int x);
    void set_y(int y);

    bool isset_x();
    bool isset_y();
    int get_x();
    int get_y();
    string test_x();
    string test_y();

    string get_value();
    string get_value_with_quote();
    void set_value(string value);

    void parser(string);
    void copy_param(SylkRecord record);
    string to_string();

protected:
private:
    int _type;
    bool _x_setFlag;
    bool _y_setFlag;
    int _x;
    int _y;
    bool _value_stringFlag;
    string _value;
};

#endif // SYLKRECORD_H
