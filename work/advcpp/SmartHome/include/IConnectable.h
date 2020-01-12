#ifndef ICONNECTABLE_H
#define ICONNECTABLE_H

#include "IEventTaker.h"

class IConnectable 
{
public:
    virtual ~IConnectable() {};
    virtual void connect(advcpp::SharedPtr<IEventTaker> const& eTaker) = 0;
};


#endif