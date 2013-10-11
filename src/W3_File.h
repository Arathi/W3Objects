#ifndef W3_FILE_H
#define W3_FILE_H

#include "IW3File.h"
#include "ObjectTable.h"
#include "Utils.h"

const int kIntegerSize=4;
const int kRealSize=4;

class W3_File : public IW3File
{
public:
    W3_File();
    virtual ~W3_File();

    void load(string);
    void save(string);
protected:
private:
    string _filename;

    int _version;
    ObjectTable _original;
    ObjectTable _custom;
};

#endif // W3_FILE_H
