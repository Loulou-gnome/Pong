#ifndef CONFIGRIG_H
#define CONFIGRIG_H

#include <vector>
#include "Config.hpp"
class MasterConfig
{
private:
    /* data */
    std::vector<Config> m_data;
    unsigned int m_count = 0;
public:
    MasterConfig();
    ~MasterConfig();
    inline void PushConfig(Config conf) { m_data.push_back(conf); m_count++; }
    inline unsigned int GetCount() const{ return m_count; } 
    inline Config ById(unsigned int index) { return m_data[index]; }
};


#endif //CONFIGRIG_H