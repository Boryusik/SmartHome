#include <iostream>
#include <unistd.h>
#include "TempSensor.h"


namespace Demo{

using namespace advcpp;
using GeneralSmartHome::Event;

TempSensor::TempSensor(devType const& a_type, DevicesSmartHome::Location const& a_locat)
:EventSensor(a_type, a_locat)
,m_isOn(true)
{
    

}

TempSensor::TempSensor(devType const& a_type, DevicesSmartHome::Location const& a_locat, Device_Id a_id, LogName const& a_logName, Conf const& a_conf)
:EventSensor(a_type, a_locat, a_id, a_logName, a_conf)
,m_isOn(true)
{
    //std::cout << "Temp sensor has been construct"<< m_isOn <<"\n";

}

TempSensor::TempSensor(DevicesSmartHome::DeviceConfig const& a_conf)
:EventSensor(a_conf.type(),a_conf.place(),a_conf.getId(),a_conf.logName(),a_conf.Configure())
,m_isOn(true)
{

}

// const devType TempSensor::s_type = "TempType";

TempSensor::~TempSensor()
{   
//  if(m_thread != 0)
//  {     
//      delete m_thread;
//  }
}


void TempSensor::connect(advcpp::SharedPtr<IEventTaker> const& a_taker)
{
    EventSensor::connect(a_taker);
    m_thread = new Thread (*this);
}

void TempSensor::disconnect()
{
    shutDown();
}

void TempSensor::shutDown()
{
    m_isOn = false;  
    std::cout << "\nSensor is shutting down... \n";  
}

void TempSensor::run()
{
    double tmp = 25;
    double dt = +1;
    while(m_isOn)  
    {
        
        sendEvent(advcpp::SharedPtr<Event>(new TempEvent(m_configuration.place(), tmp)));//TODO remove hardcoded        
        tmp += dt;
        if(tmp > 42) dt *= -1;
        if(tmp < 14) dt *= -1;
        sleep(1);
        // std::cout << "Temp_Sensor event:" << "Temperature has changed on the " << m_configuration.place().getFloor();
        // std::cout <<  " at " << m_configuration.place().getRoom()<<" !\n";
    }
    std::cout << "Sensor is off \n";
}


}

