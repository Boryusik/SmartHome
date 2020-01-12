#ifndef IEVENT_GIVER_H
#define IEVENT_GIVER_H

#include "Event.h"
#include "SharedPtr.h"


using namespace advcpp;

class IEventGiver
{
public:
    virtual ~IEventGiver(){};
    virtual SharedPtr<GeneralSmartHome::Event> get() = 0;
};


#endif