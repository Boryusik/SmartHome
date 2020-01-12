#ifndef ISUBSCRIBABLE_h
#define ISUBSCRIBABLE_h

#include "common.h"
#include "SharedPtr.h"
#include "IEventHandler.h"

class EventController;

class ISubscribable
{
public:
    virtual ~ISubscribable() = 0;
    virtual void subscribe(Type_event const& a_tEvent, DevicesSmartHome::Location const& a_loctnEvent, advcpp::SharedPtr<IEventHandler> const& a_controller) = 0;
};

#endif