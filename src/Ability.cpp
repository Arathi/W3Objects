#include "Ability.h"
#include "Config.h"

Ability::Ability()
{
    //��ʼ��Ability
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
    //�������slk�ļ�
}

void Ability::loadProfile(TextFile txt)
{
    //�������txt�ļ�
}

void Ability::loadObject(W3_File w3a)
{
    //����w3a�ļ�
}
