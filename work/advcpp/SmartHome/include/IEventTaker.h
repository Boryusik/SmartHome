#ifndef IEVENT_TAKER_H
#define IEVENT_TAKER_H

#include "Event.h"
#include "SharedPtr.h"

class IEventTaker
{
public:
    virtual ~IEventTaker(){};
    virtual void take(advcpp::SharedPtr<GeneralSmartHome::Event> const& a_event) = 0;
};



#endif