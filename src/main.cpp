#include <iostream>
#include <SFML/Graphics.hpp>
#include "Config.hpp"
#include "App.hpp"
using namespace std;

int main(int argv, char* argc[])
{
    
    Config config = App::LoadConfFromFile("Configs/Main.ini");
    
    App master(&config);

    App::Run(&master);
    return EXIT_SUCCESS;
}
