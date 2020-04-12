#include "include/Configs.hpp"

using namespace std;
Configs::Configs()
{

}
Config Configs::LoadConfFromFile(string path)
{
    Config conf;
    string line;
    ifstream myfile (path);
    if (myfile.is_open())
    {
        string lastline("no line");
        while ( getline (myfile,line) )
        {
            if(line.find('#') >= 0)
                continue;
            if(line.find('=') >= 0)
            {
            string label = line.substr(0, line.find('='));
            string value = line.substr(line.find('=')+1);
            cout << label << ':' << value << '\n';
            conf.PushConfig(label, value);
            }
            else if ( line.find('[') >= 0 && line.find(']') >= 0)
            {
                if(lastline == "no line")
                    conf.SetName(line.substr(1, line.find(']')-1));
            }
            lastline = line;

        }
        myfile.close();
    }

  else cout << "Unable to open file: " << path << '\n'; 

    return conf; 
}

ConfigRig Configs::LoadEntities(string entityfile)
{

     ConfigRig conf;
    string line;
    ifstream myfile (entityfile);
    if (myfile.is_open())
    {
        string lastline("no line");
        Config current;
        while ( getline (myfile,line) )
        {
            if(line.find('#') >= 0)
                continue;
            if(line.find('=') >= 0)
            {
            string label = line.substr(0, line.find('='));
            string value = line.substr(line.find('=')+1);
            cout << label << ':' << value << '\n';
            current.PushConfig(label, value);
            }
            else if ( line.find('[') >= 0 && line.find(']') >= 0)
            {
                if(lastline != "no line")
                {
                    conf.PushConfig(current);
                    current.Reset();
                }

            }
            lastline = line;

        }
        myfile.close();
    }

  else cout << "Unable to open file: " << entityfile << '\n'; 

    return conf; 
    

}