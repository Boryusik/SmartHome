#ifndef SERVER_H
#define SERVER_H

#include "EventManager.h"
#include "SThrDispetcher.h"
// #include "Register.h"
// #include "Router.h"
#include "Device.h"
#include <ISubscribable.h>

namespace ServerComponents{

class ShuttingDownEvent;
class Router;
class Register;


class Server
{
private: 
typedef std::vector<advcpp::SharedPtr<DevicesSmartHome::Device> > DeviceVec;

public:    
    Server();
    ~Server();
    SharedPtr<IEventTaker> getTaker();
    SharedPtr<ISubscribable> getRegistrer();
    void shutDown();
    size_t attachDevices(DeviceVec &a_devs);

private:
    void disconectDevices();
    
private:    
    advcpp::SharedPtr<EventManager>             m_emanager;
    advcpp::SharedPtr<SThrdDispetcher>          m_dispchr;
    advcpp::SharedPtr<Register>                 m_register;
    advcpp::SharedPtr<Router>                   m_router;   
    DeviceVec                                   m_devices;
};

}
#endif