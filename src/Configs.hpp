#ifndef CONFIGS_H
#define CONFIGS_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Configs
{
    public:
        Configs();
        static std::vector<std::string> LoadConfFromFile(std::string path);
        //static std::vector<std::string> BaseConfig;
        std::vector<std::string> BaseConfig = Configs::LoadConfFromFile("Configs/Main.ini") ;
        
};


#endif//CONFIGS_H