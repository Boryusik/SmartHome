#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include "IEventGiver.h"
#include "IEventTaker.h"
#include "WaitableQueue.h"


namespace ServerComponents{
using namespace advcpp;

class EventManager:  public IEventGiver, public IEventTaker
{
public:
        EventManager();
        virtual void take(SharedPtr<GeneralSmartHome::Event> const& a_event); 
        virtual SharedPtr<GeneralSmartHome::Event> get();   
        WaitableQueue<SharedPtr<GeneralSmartHome::Event> > getEventQueue() const;

private:
        WaitableQueue<SharedPtr<GeneralSmartHome::Event> >   m_eQueue;
};


}

#endif