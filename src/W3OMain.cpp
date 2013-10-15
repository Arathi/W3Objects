#include "W3OUnits.h"
#include <unistd.h>
#include "Config.h"
#include "Ability.h"

const string kVersion = "0.1.0";

void usage()
{

}

int main(int argc, char **argv)
{
    cout<<"W3Objects v"<<kVersion<<endl;
    string configPath="";
    if (argc==1)
    {
        char pwd[256];
        getcwd(pwd, sizeof(pwd));
        configPath = pwd;
        configPath += "/default.ini";
    }
    else if (argc==2)
    {
        configPath = argv[1];
    }
    else
    {
        usage();
        return 1;
    }
    Config config=Config::getConfig(configPath);
    string basePath = config.get_base_path();
    clog<<"配置目录："<<basePath<<endl;

    //UnitMain();
    //--------------以下是Ability读取的逻辑--------------
    /*
    CampaignAbilityFunc.txt
    campaignabilitystrings.txt
    CommonAbilityFunc.txt
    CommonAbilityStrings.txt
    HumanAbilityFunc.txt
    HumanAbilityStrings.txt
    ItemAbilityFunc.txt
    ItemAbilityStrings.txt
    NeutralAbilityFunc.txt
    NeutralAbilityStrings.txt
    NightElfAbilityFunc.txt
    NightElfAbilityStrings.txt
    OrcAbilityFunc.txt
    OrcAbilityStrings.txt
    UndeadAbilityFunc.txt
    UndeadAbilityStrings.txt
    */

    Ability ability;
    SylkFile slk;
    TextFile txt;
    slk.load(basePath+"AbilityData.slk");

    txt.load(basePath+"\\Units_126\\"+"ItemAbilityFunc.txt");
    txt.load(basePath+"\\Units_126\\"+"ItemAbilityStrings.txt");
    txt.save("D:\\TestDir\\mpq\\UnitsCopy\\ItemAbility.txt");

    ability.loadSylk(slk);

    //UnitMain();
    return 0;
}
