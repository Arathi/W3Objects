#ifndef IW3FILE_H_INCLUDED
#define IW3FILE_H_INCLUDED

#include "Common.h"

class IW3File
{
public:
    virtual void load(string) = 0;
    virtual void save(string) = 0;
};

#endif // IW3FILE_H_INCLUDED
