#include "include/App.hpp"

/// Run The app
void App::Run(App* application)
{
    application->Load();

    application->Init();
    
    application->MainLoop(new sf::Clock());
    application->Unload();
}



App::App(Configs conf)
{
    m_app_name = conf.BaseConfig.GetValueFromLabel("AppName");

    m_resolution.width = std::stoi(conf.BaseConfig.GetValueFromLabel("ResolX"));
    m_resolution.height = std::stoi(conf.BaseConfig.GetValueFromLabel("ResolY"));
}


// Load Graphicals things
void App::Load()
{
    m_application.create(m_resolution, m_app_name);

    // entities loading
    Entity::LoadEntities("Configs/World1/Entities.ini");
}

//init Math and logic
void App::Init()
{
    m_application.setFramerateLimit(60);
    
}

//Update Graphics and physics
void App::Update(sf::Clock Clock)
{
    

}
// Draw Sprite on screen
void App::Draw()
{
    m_application.display();
    m_application.draw(sf::Sprite(Entity::DrawEntities()));
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