#include <iostream>
#include <SFML/Graphics.hpp>
#include "include/Configs.hpp"
#include "include/App.hpp"
using namespace std;

int main(int argv, char* argc[])
{
    
    Configs config;
    config.BaseConfig = Configs::LoadConfFromFile("Configs/Main.ini");
    App::Run(new App(config));
    return EXIT_SUCCESS;
}
