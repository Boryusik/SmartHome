#include "ConfigFile.h"
#include "SharedPtr.h"
#include <iostream>
#include <string>
#include <sstream>

namespace ServerComponents{

using DevicesSmartHome::DeviceConfig;
using DevicesSmartHome::Location;


ConfigFile::ConfigFile(fileName const& a_fName)
: m_fName(a_fName.c_str())
{
    if(!m_fName.is_open())
    {
        std::string s = "cannot open file: ";
    }

    createConfigs();
}

std::vector<DevicesSmartHome::DeviceConfig> ConfigFile::getConfigs() const
{
    return m_configs;
}

void ConfigFile::createConfigs()
{
    std::stringstream str;
    std::string id;
    std::string room;
    std::string floorStr;
    std::string type;
    std::string config;
    std::string log;
    
    while(!m_fName.eof())
    {
        while(id.empty())
        {
            getline(m_fName, id);
        }

        getline(m_fName, type);
        getline(m_fName, room);
        getline(m_fName, floorStr);
        getline(m_fName, log);
        if(log.find("log =")!=log.npos)
        {
            log.replace(0,config.find("= ",0,2) + 2,"");
            getline(m_fName, config);        
        }
        else{
            config = log;  
            log="";          
        }
        config.replace(0,config.find("= ",0,2) + 2,"");
        
        type.replace(0,type.find("= ",0,2) + 2,"");
        room.replace(0,room.find("= ",0,2) + 2,"");
        floorStr.replace(0,floorStr.find("= ",0,2) + 2,"");
       

        Location loctn(room,floorStr);
      
        m_configs.push_back(DeviceConfig(type, loctn, id, log, config));
        
        id.clear();
        config.clear();
    }
}



}// ServerComponents