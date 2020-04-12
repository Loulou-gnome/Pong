#ifndef CONFIGRIG_H
#define CONFIGRIG_H

#include <vector>
#include "Config.hpp"
class ConfigRig
{
private:
    /* data */
    std::vector<Config> m_configPacked;
    unsigned int m_count = 0;
public:
    ConfigRig();
    ~ConfigRig();
    inline void PushConfig(Config conf) { m_configPacked.push_back(conf); m_count++; }
    inline unsigned int GetCount() const{ return m_count; } 
    inline Config ById(unsigned int index) { return m_configPacked[index]; }
};


#endif //CONFIGRIG_H