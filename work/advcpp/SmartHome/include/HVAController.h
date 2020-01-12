#ifndef HVAC_CONTROLER_H
#define HVAC_CONTROLER_H

#include "EventController.h"
#include "Device.h"

namespace Demo{

class HVACHandler1;
class HVACHandler2;

class HVAController : public DevicesSmartHome::EventController
{
public:
    // HVAController(Location const& a_locat);   
    // HVAController(Location const& a_locat, Device_Id a_id, LogName const& a_logName = "", Conf const& a_conf = "");

    HVAController(devType const& a_type, DevicesSmartHome::Location const& a_locat);   
    HVAController(devType const& a_type, DevicesSmartHome::Location const& a_locat, Device_Id a_id, LogName const& a_logName = "", Conf const& a_conf = "");
    HVAController(DevicesSmartHome::DeviceConfig const& a_conf);
    ~HVAController();          

    void registrate(advcpp::SharedPtr<ISubscribable> a_regstr);
       
private:    
    advcpp::SharedPtr<IEventHandler> m_handler1;
    advcpp::SharedPtr<IEventHandler> m_handler2;
    // static const devType    s_type;
};

}//namespace Demo
#endif
