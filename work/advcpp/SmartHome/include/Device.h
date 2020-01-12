#ifndef DEVICE_H
#define DEVICE_H

// #include <iostream>
#include "common.h"
#include "DeviceConfig.h"

namespace DevicesSmartHome{

class Device
{
public:
    Device(devType const& a_type, Location const& a_locat);           
    Device(devType const& a_type, Location const& a_locat, Device_Id a_id, LogName const& a_logName = "", Conf const& a_conf = "");    
    virtual ~Device() = 0;
    virtual void disconnect() = 0;
    
protected:
    DeviceConfig        m_configuration;   

};

}
#endif