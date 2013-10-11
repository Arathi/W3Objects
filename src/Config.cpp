#include "Config.h"

Config* Config::_config = NULL;
string Config::_default_path = "";

Config::Config(string path)
{
    //ctor
    ifstream fin(path.c_str());
    if (fin.good())
    {
        _base_path = "D:\\TestDir\\mpq\\";
    }
    else
    {
        clog<<"配置文件打开失败，设置为默认路径"<<endl;
        _base_path = "D:\\TestDir\\mpq\\";
    }
}

Config::~Config()
{
    //dtor
}

Config& Config::getConfig(string path)
{
    if (_config==NULL)
    {
        string configPath="";
        char pwd[256];
        getcwd(pwd, sizeof(pwd));
        configPath = pwd;

        if (path!="")
        {
            configPath=path;
        }
        else
        {
            _default_path = pwd;
            configPath += "/default.ini";
        }
        _config = new Config(configPath);
    }
    return *_config;
}

string Config::get_base_path()
{
    return _base_path;
}
