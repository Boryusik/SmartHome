#ifndef DEVICE_CONFIG_H
#define DEVICE_CONFIG_H

#include "common.h"

namespace DevicesSmartHome{

class Location
{
public:
     Location();
     Location(Room const& a_room, Floor const& a_floor);
     bool operator<(Location const& _rhs) const;
     Room const& getRoom() const;
     Floor const& getFloor() const;

private:
    Room    m_room;
    Floor   m_floor;
};

class DeviceConfig
{
public:
    DeviceConfig();
    DeviceConfig(devType const& a_type, Location const& a_loctn, Device_Id a_id = "", LogName const& a_lName = "", Conf const& a_conf = "" );
    
    devType const& type() const;
    Device_Id getId() const;
    Location const& place() const;
    LogName const&  logName() const;
    Conf const& Configure() const;

private:
    Device_Id       m_devId;
    devType         m_type;
    Location        m_location; 
    LogName         m_logType;
    Conf            m_configure;
};


inline devType const& DeviceConfig::type() const
{
    return m_type;
}

inline Device_Id DeviceConfig::getId() const
{
    return m_devId;
}

inline Location const & DeviceConfig::place() const
{
    return m_location;
}

inline LogName const&  DeviceConfig::logName() const
{
    return m_logType;
}

inline  Conf const& DeviceConfig::Configure() const
{
    return m_configure;
}

}

#endif