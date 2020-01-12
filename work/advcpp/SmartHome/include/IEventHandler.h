#ifndef IEVENT_HANDLER_H
#define IEVENT_HANDLER_H

#include "SharedPtr.h"
#include "Event.h"

class IEventHandler
{
public:
    virtual ~IEventHandler(){} ;
    virtual void handleEvent(advcpp::SharedPtr<GeneralSmartHome::Event>& a_event) const= 0;
};

#endif