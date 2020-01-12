#ifndef ROUTER_H
#define ROUTER_H

#include "Runnable.h"
#include "Thread.h"
#include "IEventGiver.h"
#include "IDispetcher.h"
#include "ILookable.h"
#include "SharedPtr.h"

namespace ServerComponents{

class Router
{
public:
    Router(SharedPtr<IEventGiver> const& a_evntGiver, SharedPtr<IDispetcher> const& a_disp, SharedPtr<ILookable> const& a_looker);
    ~Router(); 
    void off();   
    class ServerWorker: public advcpp::IRunnable
    {
    public:        
        ServerWorker(Router& a_rout);
        void run();
        void off();

    private:
        bool      m_isOn;
        Router&   m_rout;

    };
private:    
    ServerWorker                      m_worker; 
    advcpp::SharedPtr<IEventGiver>    m_evntGiver;
    advcpp::SharedPtr<IDispetcher>    m_dispetcher;   
    advcpp::SharedPtr<ILookable>      m_looker;
    advcpp::Thread                    m_thread;
   
};

}//ServerComponents
#endif