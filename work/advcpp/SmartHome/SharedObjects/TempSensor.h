#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include "EventSensor.h"
#include "Thread.h"

namespace SharedObjects{

class TempSensor : public DevicesSmartHome::EventSensor, public advcpp::IRunnable
{
public:
    TempSensor(devType const& a_type, DevicesSmartHome::Location const& a_locat);
    TempSensor(devType const& a_type, DevicesSmartHome::Location const& a_locat, Device_Id a_id, LogName const& a_logName = "", Conf const& a_conf = "");
    TempSensor(DevicesSmartHome::DeviceConfig const& a_conf);
    ~TempSensor();
    void run();
    void shutDown();
    void disconnect();
    virtual void connect(advcpp::SharedPtr<IEventTaker> const& a_taker);
      
private:
    advcpp::Thread*               m_thread; 
    bool                          m_isOn;
};


}//namespace Demo

#endif
