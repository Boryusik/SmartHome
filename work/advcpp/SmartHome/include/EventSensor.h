#ifndef SENSOR_EVENT
#define SENSOR_EVENT

#include "Device.h"
#include "IConnectable.h"
#include "Event.h"

namespace DevicesSmartHome{

class EventSensor : public Device , public IConnectable
{
public:
    EventSensor(devType const&, Location const& a_locat);
    EventSensor(devType const& a_type, Location const& a_locat, Device_Id a_id, LogName const& a_logName = "", Conf const& a_conf = "");
    ~EventSensor();
    void connect(advcpp::SharedPtr<IEventTaker> const& a_taker);
   
protected:
    void sendEvent(advcpp::SharedPtr<GeneralSmartHome::Event> const& e);
    
private:
    advcpp::SharedPtr<IEventTaker>   m_taker;
};

}//DevicesSmartHome
#endif