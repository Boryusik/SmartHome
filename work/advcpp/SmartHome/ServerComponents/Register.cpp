#include "Register.h"

ISubscribable::~ISubscribable()
{

}

ILookable::~ILookable()
{

}


namespace ServerComponents{

using DevicesSmartHome::Location;

Register::Register()
{

}

Register::~Register()
{

}

void Register::subscribe(Type_event const& a_tEvent, Location const& a_loctnEvent, advcpp::SharedPtr<IEventHandler> const& a_controller)
{
    std::pair<Type_event, Location> 
            evntKey = std::make_pair(a_tEvent, a_loctnEvent);
    
    m_subscribeMap[evntKey].push_back(a_controller);     
}


CtrlVec const* Register::findFollowers(Type_event const& a_tEvent, Location const& a_loc) const
{
    RegMap::const_iterator it;
    std::pair <Type_event ,Location> evntKey;
    evntKey = std::make_pair(a_tEvent, a_loc);

    it = m_subscribeMap.find(evntKey);
    
    if(it != m_subscribeMap.end())
    {
       return &(it->second);           
    }   

    return 0; 
}

}