#ifndef CONFIGS_H
#define CONFIGS_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Entity.hpp"
#include "Config.hpp"
#include "ConfigRig.hpp"
class Configs
{
    public:
        Configs();
        /// Load a .ini File into a vector of strings you'll have to remember 
        /// how many options there are into that .ini file
        static Config LoadConfFromFile(std::string path);
        /// Load an Entities.ini file into an Entity vector
        static ConfigRig LoadEntities(std::string path);
        // Base config for an app.
        Config BaseConfig = Configs::LoadConfFromFile("Configs/Main.ini") ;
};


#endif//CONFIGS_H