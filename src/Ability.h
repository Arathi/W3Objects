#ifndef ABILITY_H
#define ABILITY_H

#include "SylkFile.h"
#include "TextFile.h"
#include "W3_File.h"

class Ability
{
public:
    Ability();
    virtual ~Ability();

    void loadSylk(SylkFile slk);
    void loadProfile(TextFile txt);
    void loadObject(W3_File w3a);
protected:
private:
    SylkFile _meta;
};

#endif // ABILITY_H
