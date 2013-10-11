#include "Ability.h"
#include "Config.h"

Ability::Ability()
{
    //初始化Ability
    Config config = Config::getConfig();
    string basePath = config.get_base_path();
    _meta.load(basePath+"/AbilityMetaData.slk");
}

Ability::~Ability()
{
    //dtor
}

void Ability::loadSylk(SylkFile slk)
{
    //载入各个slk文件
}

void Ability::loadProfile(TextFile txt)
{
    //载入各个txt文件
}

void Ability::loadObject(W3_File w3a)
{
    //载入w3a文件
}
