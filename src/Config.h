#ifndef CONFIG_H
#define CONFIG_H

#include "Common.h"
#include <unistd.h>

class Config
{
public:
    virtual ~Config();
    static Config& getConfig(string path="");

    string get_base_path();
protected:
private:
    Config(string path);

    static Config* _config;
    static string _default_path;
    string _base_path;
};

#endif // CONFIG_H
