#include "TempEvent.h"

namespace SharedObjects{

using DevicesSmartHome::Location;

TempEvent::TempEvent(Location const& a_location, timestamp const& a_time)
:Event(a_location, a_time )
{
    s_eType = "ambient_temp";
}


}//namespace Demo
