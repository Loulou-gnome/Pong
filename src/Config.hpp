#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <vector>
#include <iostream>

class Config
{

    public:
        Config();
        inline void SetName(std::string name) { m_name = name; }
        inline void Reset() { m_labels.clear(); m_values.clear(); m_name = "";}
        inline void PushConfig(std::string label, std::string value) { m_labels.push_back(label); m_values.push_back(value);}
        std::string GetValueFromLabel(std::string label);
        std::string GetLabelFromValue(std::string value);
        inline std::string GetName() const { return m_name; }
    protected:

        std::string m_name;
        std::vector<std::string> m_labels;
        std::vector<std::string> m_values;

};

#endif //CONFIG_H