#include "Configs.hpp"

using namespace std;
Configs::Configs()
{

}
vector<string> Configs::LoadConfFromFile(string path)
{
    vector<string> conf(0);
    string line;
    ifstream myfile (path);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            cout << line << '\n';
            string label = line.substr(0, line.find('='));
            string value = line.substr(line.find('=')+1);
            cout << label << ':' << value << '\n';
            conf.push_back(value);
        }
        myfile.close();
    }

  else cout << "Unable to open file"; 

    return conf; 
}