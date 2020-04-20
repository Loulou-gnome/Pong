#include "App.hpp"


using namespace std;
/// Run The app
void App::Run(App* application)
{
    application->Load();

    application->Init();
    
    application->MainLoop(new sf::Clock());
    application->Unload();
}


Config App::LoadConfFromFile(string path)
{
    Config conf;
    string line;
    ifstream myfile (path);
    if (myfile.is_open())
    {
        string lastline("no line");
        while ( getline (myfile,line) )
        {
            if(line.find('=') >= 1)
            {
                string label = line.substr(0, line.find('='));
                string value = line.substr(line.find('=')+1);
                conf.PushConfig(label, value);
            }
            
            lastline = line;

        }
        myfile.close();
    }

  else cout << "Unable to open file: " << path << '\n'; 

    return conf; 
}



App::App(Config *conf)
{
    BaseOptions = conf;
    m_app_name = BaseOptions->GetValueFromLabel("Name");
    m_resolution.width = std::stoi(BaseOptions->GetValueFromLabel("ResolX"));
    m_resolution.height = std::stoi(BaseOptions->GetValueFromLabel("ResolY"));
    m_current_world = new World();
}

App::~App()
{

    delete m_current_world;
    delete BaseOptions;
    
}

// Load Graphicals things
void App::Load()
{
    m_application.create(m_resolution, m_app_name);

    // entities loading
    m_current_world->LoadEntities("Configs/World1/Entities.ini");
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
    
    // Draw things

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