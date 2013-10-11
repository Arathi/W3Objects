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
    Ability ability;
    SylkFile slk;
    slk.load(basePath+"AbilityData.slk");
    ability.loadSylk(slk);

    return 0;
}
