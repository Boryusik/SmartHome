#include "Event.h"


namespace GeneralSmartHome{

using DevicesSmartHome::DeviceConfig;

Event::Event()
{

}

Event::~Event()
{

}

Event::Event(DevicesSmartHome::Location const& a_location, timestamp const& a_time)
:m_location(a_location)
,m_eventTime(a_time)
{

}

Type_event Event::s_eType = "Base";


Type_event const& Event::type() const
{
    return s_eType;
}

DevicesSmartHome::Location const& Event::getLocation() const
{
    return m_location;
}


timestamp const& Event::timeEvent() const
{
    return m_eventTime;
}

ShuttingDownEvent::ShuttingDownEvent()
{
}

}