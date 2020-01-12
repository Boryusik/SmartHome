#include "EventController.h"
#include "Register.h"

namespace DevicesSmartHome{

EventController::EventController(devType const& a_type, Location const& a_locat)
:Device(a_type, a_locat)
{

}


EventController::EventController(devType const& a_type, Location const& a_locat, Device_Id a_id, LogName const& a_logName, Conf const& a_conf)
:Device(a_type, a_locat, a_id, a_logName, a_conf)
{

}

EventController::~EventController()
{

}   

void EventController::disconnect()
{

}

// void EventController::registrate(Register& a_regstr)
// {
//     // m_configuration.type();
//     a_regstr.subscribe(m_configuration.type(), advcpp::SharedPtr<IEventHandler>(this));

// } 
}