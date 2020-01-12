#ifndef EVENT_H
#define EVENT_H

#include "common.h"
#include "DeviceConfig.h"

namespace GeneralSmartHome{
class Event
{
public:
    Event();
    Event(DevicesSmartHome::Location const& a_location, timestamp const& a_time );
    virtual ~Event() = 0;
    Type_event const& type() const;
    DevicesSmartHome::Location const& getLocation() const;
    timestamp const& timeEvent() const;

private:
    DevicesSmartHome::Location        m_location;
    timestamp                         m_eventTime; 

protected:
    static Type_event s_eType;
};

class ShuttingDownEvent : public Event
{
public: 
    ShuttingDownEvent();
};

}//GeneralSmartHome
#endif