#include "Config.hpp"
using namespace std;

Config::Config() 
{
    m_labels = vector<string>(0);
    m_values = vector<string>(0); 
    m_name = "";
}


string Config::GetValueFromLabel(string label)
{
    for(unsigned int i = 0; i < m_values.size(); i++)
    {
        if(m_labels[i] == label)
            return m_values[i];

        
    }
    return "novalue";
}
string Config::GetLabelFromValue(string value)
{
    for(unsigned int i = 0; i < m_labels.size(); i++)
    {
        if(m_values[i] == value)
            return m_labels[i];
        
    }
    return "novalue";
}