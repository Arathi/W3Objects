#ifndef W3_FILE_H
#define W3_FILE_H

#include "IW3File.h"

class W3_File : public IW3File
{
public:
    W3_File();
    virtual ~W3_File();
protected:
private:
    int _version;
    ObjectTable _original;
    ObjectTable _custom;
};

#endif // W3_FILE_H
