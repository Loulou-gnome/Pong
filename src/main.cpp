#include <iostream>
#include <SFML/Graphics.hpp>
#include "Configs.hpp"
#include "App.hpp"
using namespace std;

int main(int argv, char* argc[])
{
    
    Configs config;
    config.BaseConfig = Configs::LoadConfFromFile("Configs/Main.ini");
    App::Run(new App(config.BaseConfig[0], config.BaseConfig[1], config.BaseConfig[2]));
    return EXIT_SUCCESS;
}
