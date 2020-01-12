#include "DeviceConfig.h"

namespace DevicesSmartHome{
//Function for Location class
Location::Location()
{

}

Location::Location(Room const& a_room, Floor const& a_floor)
:m_room(a_room)
,m_floor(a_floor)
{

}

Room const& Location::getRoom() const
{
    return m_room;
}

Floor const& Location::getFloor() const
{
    return m_floor;
}

bool Location::operator<(Location const& _rhs) const
{
    if(m_floor < _rhs.getFloor())
        return true;
    if(m_floor == _rhs.getFloor()){
        if(m_room < _rhs.getRoom() )
            return true;
    }
    
    return false;
}

// function for Device Config class
DeviceConfig::DeviceConfig()
{

}

DeviceConfig::DeviceConfig(devType const& a_type, Location const& a_locat, Device_Id a_id, LogName const& a_logName, Conf const& a_conf)
:m_devId(a_id)
,m_type(a_type)
,m_location(a_locat)
,m_logType(a_logName)
,m_configure(a_conf)
{

}

}
