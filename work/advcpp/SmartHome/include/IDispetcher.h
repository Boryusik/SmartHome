#ifndef IDISPETCHER_H
#define IDISPETCHER_H

#include <vector>
#include "Event.h"
#include "IEventHandler.h"
#include "SharedPtr.h"

class IDispetcher
{
public:
    virtual ~IDispetcher(){}
    virtual void send(advcpp::SharedPtr<GeneralSmartHome::Event> const& a_evnt, std::vector<advcpp::SharedPtr<IEventHandler> >const* a_handlers) = 0;
};


#endif