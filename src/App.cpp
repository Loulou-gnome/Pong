#include "App.hpp"

/// Run The app
void App::Run(App* application)
{
    application->Load();

    application->Init();
    
    application->MainLoop(new sf::Clock());
    application->Unload();
}



App::App(std::string appname, std::string resx, std::string resy)
{
    m_app_name = appname;

    m_resolution.width = std::stoi(resx);
    m_resolution.height = std::stoi(resy);
}


// Load Graphicals things
void App::Load()
{

    // entities loading
}

//init Math and logic
void App::Init()
{
    m_application.setFramerateLimit(60);
    m_application.create(m_resolution, m_app_name);

}

//Update Graphics and physics
void App::Update(sf::Clock Clock)
{
    

}
// Draw Sprite on screen
void App::Draw()
{
    m_application.display();

    m_application.clear();


}
// Unload Graĥical contents
void App::Unload()
{


}


// Default main loop
void App::MainLoop(sf::Clock* Clock)
{
    while(m_application.isOpen())
    {
        EventLoop();

        Update(*Clock);
        Draw();
    }
}
// Default Event Loop
void App::EventLoop()
{
    while(m_application.pollEvent(m_event))
    {

        switch(m_event.type)
        {

            case sf::Event::Closed:
                m_application.close();
            break;
            default:

            break;
        }
    }
}