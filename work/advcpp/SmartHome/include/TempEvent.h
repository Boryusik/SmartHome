#ifndef TEMP_EVENT_H
#define TEMP_EVENT_H

#include "Event.h"

namespace Demo{

class TempEvent : public GeneralSmartHome::Event
{
public:
    TempEvent(DevicesSmartHome::Location const& a_location, timestamp const& a_time);

private:     

};


}


#endif