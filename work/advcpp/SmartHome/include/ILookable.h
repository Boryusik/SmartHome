#ifndef ILOOKABLE_H
#define ILOOKABLE_H

#include "SharedPtr.h"
#include <vector>

class EventController;
class ILookable
{
public:
    virtual ~ILookable() = 0;
    virtual std::vector<advcpp::SharedPtr<IEventHandler> >const* findFollowers(Type_event const& a_tEvent, DevicesSmartHome::Location const& a_loc) const = 0;
};

#endif