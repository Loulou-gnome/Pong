#ifndef APP_H
#define APP_H
#include <SFML/Graphics.hpp>
class App
{
    public:
        App(std::string appname, std::string resx, std::string resy);
        static void Run(App* application = nullptr);
        void Load();
        void Init();
        void Update(sf::Clock Clock);
        void Draw();
        void Unload();
        void MainLoop(sf::Clock* Clock = nullptr);
        void EventLoop();
    protected:
        std::string m_app_name;
        sf::Event m_event;
        sf::VideoMode m_resolution;
        sf::RenderWindow m_application;
};


#endif //APP_H
