#ifndef ICONTROLLER_H
#define ICONTROLLER_H

// #include "Register.h"
#include "IEventHandler.h"
#include "Device.h"
#include "common.h"
#include "ISubscribable.h"
#include "SharedPtr.h"

namespace DevicesSmartHome{
class Register;

class EventController : public  Device
{
public:
    EventController(devType const& a_type, Location const& a_locat);
    EventController(devType const& a_type, Location const& a_locat, Device_Id a_id, LogName const& a_logName = "", Conf const& a_conf = "");
    ~EventController();   
    
    virtual void registrate(advcpp::SharedPtr<ISubscribable> a_regstr) = 0;
    virtual void disconnect();
 };

}
#endif