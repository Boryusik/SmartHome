#include <unistd.h>
#include "Server.h"
#include "EventSensor.h"
#include "EventController.h"
// #include "TempSensor.h"
// #include "HVAController.h"
#include "Router.h"
#include <Register.h>


namespace ServerComponents{


using DevicesSmartHome::Device;
using DevicesSmartHome::EventSensor;
using GeneralSmartHome::Event;

Server::Server()
: m_emanager(new EventManager)
, m_dispchr(new SThrdDispetcher)
, m_register(new Register)
, m_router(new Router(m_emanager, m_dispchr, m_register))
{

}

Server::~Server()
{
    
}

SharedPtr<IEventTaker> Server::getTaker()
{
    return m_emanager;
}

SharedPtr<ISubscribable> Server::getRegistrer()
{
    return m_register;
}

void Server::shutDown()
{    
    advcpp::SharedPtr<Event> shutDwEv(new GeneralSmartHome::ShuttingDownEvent());
    m_emanager->take(shutDwEv);
    m_dispchr->shutDown();

    disconectDevices();
    
    sleep(5);
}

void Server::disconectDevices()
{
    std::vector <advcpp::SharedPtr<Device> >::iterator bit = m_devices.begin();
    std::vector <advcpp::SharedPtr<Device> >::iterator eit = m_devices.end();

    while(bit != eit)
    {
        (*bit)->disconnect();        
        ++bit;
    }
}

size_t Server::attachDevices(std::vector<SharedPtr<Device> > & a_devs)
{
    SharedPtr<IEventTaker> taker = getTaker();
    SharedPtr<ISubscribable> reg = getRegistrer();
    size_t n = 0;
    for( size_t i = 0; i< a_devs.size(); ++ i)
    {        
        bool added = false;
        EventSensor* ts = dynamic_cast<EventSensor*>(&*a_devs[i]);
        if(ts != 0)
        {            
            ts->connect(taker);                            
            added = true;
        }

        DevicesSmartHome::EventController* tc = dynamic_cast<DevicesSmartHome::EventController*>(&*a_devs[i]);
        if(tc != 0)
        {            
            tc->registrate(reg);                    
            added = true;
        }        

        if(added){
            m_devices.push_back(a_devs[i]);
            ++n;
        }
    }    

    return n;
}

}



