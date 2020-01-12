#ifndef REGISTRATOR_H
#define REGISTRATOR_H

#include <map>
#include <vector>
#include "ISubscribable.h"
#include "ILookable.h"

namespace ServerComponents{

typedef std::vector<advcpp::SharedPtr<IEventHandler> > CtrlVec;
typedef std::pair <Type_event, DevicesSmartHome::Location>  EventKey;
typedef std::map<EventKey, CtrlVec > RegMap;

class Register : public ISubscribable, public ILookable
{
public:          
    Register();   
    ~Register();
    virtual void subscribe(Type_event const& a_tEvent, DevicesSmartHome::Location const& a_loctnEvent, advcpp::SharedPtr<IEventHandler> const& a_controller);
    virtual CtrlVec const* findFollowers(Type_event const& a_tEvent,DevicesSmartHome::Location const& a_loc) const;
    RegMap const& getRegMap() const;    
    
private: 
    // Mutex   m_locker;
    RegMap m_subscribeMap;
};

inline RegMap const& Register::getRegMap() const
{
    return m_subscribeMap;
}

}

#endif