#ifndef APP_H
#define APP_H
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include "Config.hpp"
#include "World.hpp"

/// Main class.
class App
{
    public:

        /// Load an ini file.
        static Config LoadConfFromFile(std::string path);
        
        /// Run an application each app as its own event, resolution, and renderwindow instance.
        static void Run(App* = nullptr);

        /// Constructor
        App(Config* = nullptr);
        
        /// Destructor
        virtual ~App();
        
        /// Load all graphical parts of the app.
        void Load();
        /// Init all logical parts of the app.
        void Init();
        /// Update all sprites.
        void Update(sf::Clock);
        /// Draw all sprites on screen.
        void Draw();
        /// Unload all graphicals contents.
        void Unload();
        /// Main Loop that handle eventLoop , update and draw methods.
        void MainLoop(sf::Clock* = nullptr);
        /// Event Loop that handle ..... events.
        void EventLoop();
    protected:
        std::string m_app_name;
        sf::Event m_event;
        sf::VideoMode m_resolution;
        sf::RenderWindow m_application;
        Config *BaseOptions = nullptr;
        World *m_current_world = nullptr;

};


#endif //APP_H
