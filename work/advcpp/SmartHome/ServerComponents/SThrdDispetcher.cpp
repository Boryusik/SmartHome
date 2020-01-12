#include "SThrDispetcher.h"

namespace ServerComponents{
using namespace advcpp;
using GeneralSmartHome::Event;


class RunnableWrapper: public IRunnable
{
public:
    RunnableWrapper(SharedPtr<Event> const& a_evnt, SharedPtr<IEventHandler> const& a_handler);
    void run();
private:
    SharedPtr<Event>          m_evnt;
    SharedPtr<IEventHandler>  m_handler;
};

RunnableWrapper::RunnableWrapper(SharedPtr<Event> const& a_evnt, SharedPtr<IEventHandler> const& a_handler)
:m_evnt(a_evnt)
,m_handler(a_handler)
{

}


void RunnableWrapper::run()
{
    m_handler->handleEvent(m_evnt);
}


SThrdDispetcher::SThrdDispetcher(size_t n_threads)
:m_pool(n_threads)
{

}


void SThrdDispetcher::send(SharedPtr<Event> const& a_evnt, std::vector<advcpp::SharedPtr<IEventHandler> >const* a_handlers)
{
    if(a_handlers == 0)
    {
        return;
    }
    std::vector<advcpp::SharedPtr<IEventHandler> >::const_iterator it = a_handlers->begin();

    while(it!= a_handlers->end())
    {
        sendToEachHanler(a_evnt, *it);
        ++it;
    }
}

void SThrdDispetcher::sendToEachHanler(SharedPtr<Event> const& a_evnt, advcpp::SharedPtr<IEventHandler> const& a_handler)
{
    
    SharedPtr<IRunnable> r(new RunnableWrapper(a_evnt, a_handler));
    m_pool.submit(r); 

}


void SThrdDispetcher::shutDown()
{
    m_pool.shutDown();
}

}