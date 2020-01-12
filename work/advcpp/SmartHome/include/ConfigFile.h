#ifndef CONFIG_FILE_H
#define CONFIG_FILE_H

#include "common.h"
#include "DeviceConfig.h"
#include <fstream>
#include <vector>

namespace ServerComponents{


class ConfigFile
{
public:
    ConfigFile(fileName const& a_fName);
    std::vector<DevicesSmartHome::DeviceConfig> getConfigs() const;

private:
    void createConfigs();
private:
    std::ifstream                                m_fName;
    std::vector<DevicesSmartHome::DeviceConfig>  m_configs;
};

}


#endif