#include "EventManager.h"

namespace ServerComponents{

using GeneralSmartHome::Event;

EventManager::EventManager()
{
}
 
void EventManager::take(SharedPtr<Event> const& a_event)
{
    m_eQueue.enqueue(a_event);
}

SharedPtr<Event> EventManager::get()
{
    SharedPtr<Event> she;
    m_eQueue.dequeue(she);
    return she;
}

WaitableQueue<SharedPtr<Event> > EventManager::getEventQueue() const
{
 return m_eQueue;
}

}