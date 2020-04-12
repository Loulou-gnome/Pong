#include "include/Config.hpp"
using namespace std;
string Config::GetValueFromLabel(string label)
{
    for(int i = 0; i < m_values.size(); i++)
    {
        if(m_labels[i] == label)
            return m_values[i];

    }
}
string Config::GetLabelFromValue(string value)
{
    for(int i = 0; i < m_labels.size(); i++)
    {
        if(m_values[i] == value)
            return m_labels[i];

    }
}