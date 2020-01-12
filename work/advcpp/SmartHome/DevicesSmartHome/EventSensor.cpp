#include "EventSensor.h"

namespace DevicesSmartHome{

using GeneralSmartHome::Event;

EventSensor::EventSensor(devType const& a_type, Location const& a_locat)
:Device(a_type, a_locat)
{

}

EventSensor::EventSensor(devType const& a_type, Location const& a_locat, Device_Id a_id, LogName const& a_logName, Conf const& a_conf)
:Device(a_type, a_locat, a_id, a_logName, a_conf)
{    

}

EventSensor::~EventSensor()
{
}


void EventSensor::connect(advcpp::SharedPtr<IEventTaker> const& a_taker)
{
    m_taker = a_taker;
}


void EventSensor::sendEvent(advcpp::SharedPtr<Event> const& e)
{
        m_taker->take(e);
}

}