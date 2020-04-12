#ifndef APP_H
#define APP_H
#include <SFML/Graphics.hpp>
#include "Configs.hpp"
class App
{
    public:
        App(Configs conf);
        /// Run an application each app as its own event, resolution, and renderwindow instance.
        static void Run(App* application = nullptr);
        /// Load all graphical parts of the app.
        void Load();
        /// Init all logical parts of the app.
        void Init();
        /// Update all sprites.
        void Update(sf::Clock Clock);
        /// Draw all sprites on screen.
        void Draw();
        /// Unload all graphicals contents.
        void Unload();
        /// Main Loop that handle eventLoop , update and draw methods.
        void MainLoop(sf::Clock* Clock = nullptr);
        /// Event Loop that handle ..... events.
        void EventLoop();
    protected:
        std::string m_app_name;
        sf::Event m_event;
        sf::VideoMode m_resolution;
        sf::RenderWindow m_application;
};


#endif //APP_H
