#include "World.hpp"

World::World()
{
    
}

World::~World()
{
    delete entities;
}

using namespace std;


void World::LoadMap(string mapfile)
{
    string line;
    ifstream myfile (mapfile);
    if (myfile.is_open())
    {
        string lastline("no line");
        Config current;
        while ( getline (myfile,line) )
        {
            if(line.find('=') >= 0)
            {
            string label = line.substr(0, line.find('='));
            string value = line.substr(line.find('=')+1);
            current.PushConfig(label, value);
            }
            else if ( line.find('[') >= 0 && line.find(']') >= 0)
            {
                if(lastline != "no line")
                {
                    //map->push_back(Tile(current));
                    current.Reset();
                }

            }
            lastline = line;

        }
        myfile.close();
    }

  else cout << "Unable to open file: " << mapfile << '\n'; 
 
    

}
void World::LoadEntities(string entityfile)
{

    string line;
    ifstream myfile (entityfile);
    if (myfile.is_open())
    {
        string lastline("no line");
        Config current;
        while ( getline (myfile,line) )
        {

            if(line.find('=') >= 0)
            {
            string label = line.substr(0, line.find('='));
            string value = line.substr(line.find('=')+1);
            current.PushConfig(label, value);
            }
            else if ( line.find('[') >= 0 && line.find(']') >= 0)
            {
                if(lastline != "no line")
                {
                    entities->push_back(Entity(current));
                    current.Reset();
                }

            }
            lastline = line;

        }
        myfile.close();
    }

  else cout << "Unable to open file: " << entityfile << '\n'; 
 
    

}