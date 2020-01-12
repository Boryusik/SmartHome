#include <iostream>
#include <string>
#include "Device.h"

namespace DevicesSmartHome{


Device::Device(devType const& a_type, Location const& a_locat)
:m_configuration(a_type, a_locat)
{

}

Device::Device(devType const& a_type, Location const& a_locat, Device_Id a_id, LogName const& a_logName, Conf const& a_conf)
:m_configuration(a_type,a_locat,a_id, a_logName, a_conf)
{

}

Device::~Device()
{
}

}
