#include "HVAController.h"

namespace SharedObjects{
// const devType HVAController::s_type = "TempType";

using GeneralSmartHome::Event;


HVAController::HVAController(devType const& a_type, DevicesSmartHome::Location const& a_locat)
:EventController(a_type, a_locat)
{

}

HVAController::HVAController(devType const& a_type, DevicesSmartHome::Location const& a_locat, Device_Id a_id, LogName const& a_logName, Conf const& a_conf)
:EventController(a_type, a_locat, a_id, a_logName, a_conf)
{
    
}

HVAController::HVAController(DevicesSmartHome::DeviceConfig const& a_conf)
:EventController(a_conf.type(),a_conf.place(),a_conf.getId(),a_conf.logName(),a_conf.Configure())
{

}


HVAController::~HVAController()
{

}  





class HVACHandler1 : public IEventHandler {
    void handleEvent(advcpp::SharedPtr<Event>& a_event) const;
};

void HVACHandler1::handleEvent(advcpp::SharedPtr<Event>& a_event) const
{
    std::cout << "HVAC_1:"<< a_event->type();
    std::cout << " [" << a_event->getLocation().getFloor() << " | "<< a_event->getLocation().getRoom();
    std::cout <<"] @: " << a_event->timeEvent() << "\n";       
}

class HVACHandler2 : public IEventHandler {
    void handleEvent(advcpp::SharedPtr<Event>& a_event) const;
};

void HVACHandler2::handleEvent(advcpp::SharedPtr<Event>& a_event) const
{
    std::cout << "HVAC_2:"<< a_event->type();
    std::cout << " [" << a_event->getLocation().getFloor() << " | "<< a_event->getLocation().getRoom();
    std::cout <<"] @: " << a_event->timeEvent() << "\n";       
}


void HVAController::registrate(advcpp::SharedPtr<ISubscribable> a_regstr)
{
    m_handler1 = advcpp::SharedPtr<IEventHandler>(new HVACHandler1);
    m_handler2 = advcpp::SharedPtr<IEventHandler>(new HVACHandler2);
    a_regstr->subscribe("ambient_temp", m_configuration.place(), m_handler1);
    a_regstr->subscribe("ambient_temp", m_configuration.place(), m_handler2);
}

extern "C"
advcpp::SharedPtr<DevicesSmartHome::Device> MakeDevice(DevicesSmartHome::DeviceConfig const& a_conf)
{
    return advcpp::SharedPtr<DevicesSmartHome::Device>(new HVAController(a_conf));
}

}//namespace SharedObjects{