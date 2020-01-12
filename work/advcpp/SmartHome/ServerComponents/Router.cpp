#include "Router.h"

namespace ServerComponents{

using GeneralSmartHome::Event;


Router::ServerWorker::ServerWorker(Router& a_rout)
:m_isOn(true)
,m_rout(a_rout)
{

}

void Router::ServerWorker::run()
{
    while(true)
    {      
        advcpp::SharedPtr<Event> evnt(m_rout.m_evntGiver->get()); //get event from wqueue
        using GeneralSmartHome::ShuttingDownEvent;       
        if(dynamic_cast<ShuttingDownEvent*>(&(*evnt)))
        {
            break;
        } 

        std::vector<advcpp::SharedPtr<IEventHandler> >const* handlers = m_rout.m_looker->findFollowers(evnt->type(), evnt->getLocation());
        m_rout.m_dispetcher->send(evnt, handlers);
    }    
}

void Router::ServerWorker::off()
{
    m_isOn = false;
}

Router::Router(SharedPtr<IEventGiver> const& a_evntGiver, SharedPtr<IDispetcher> const& a_disp, SharedPtr<ILookable> const& a_looker)
:m_worker(*this)
,m_evntGiver(a_evntGiver)
,m_dispetcher(a_disp)
,m_looker(a_looker)
,m_thread(m_worker)
{
}

Router::~Router()
{
    // m_thread.join();
}

void Router::off()
{
   m_worker.off();
}

}
