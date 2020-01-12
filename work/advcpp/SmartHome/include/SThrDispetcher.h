#ifndef ISHARED_DISPETCHER_H
#define ISHARED_DISPETCHER_H


#include "IDispetcher.h"
#include "ThreadPoolExecutor.h" 

namespace ServerComponents{

class SThrdDispetcher : public IDispetcher
{
public:
    SThrdDispetcher(size_t n_threads = 1);
    virtual void send(advcpp::SharedPtr<GeneralSmartHome::Event> const& a_evnt, std::vector<advcpp::SharedPtr<IEventHandler> >const* a_handlers);
    void shutDown();
public:    
    void sendToEachHanler(advcpp::SharedPtr<GeneralSmartHome::Event> const& a_evnt, advcpp::SharedPtr<IEventHandler> const& a_handlers);

private:
    advcpp::ThreadPoolExecutor    m_pool; 
 
};

}

#endif


