#include "DeviceLoader.h"
#include "EventController.h"
#include "EventSensor.h"
#include "BuilderSo.h"
#include <dlfcn.h>

namespace ServerComponents{

using Demo::TempSensor;
using Demo::HVAController;
using DevicesSmartHome::DeviceConfig;
using DevicesSmartHome::Device;
using namespace advcpp;

DeviceLoader::DeviceLoader()
{

}

advcpp::SharedPtr<Device> DeviceLoader::BuildDevice(DeviceConfig const& a_dConf)
{
    BuilderSo so(a_dConf.type());                    // load shared library: babySensor --> libbabySensor.so
    SharedPtr<Device> dev = so.makeDevice(a_dConf);  // dlsym(hm, "makeDevice") + call maker function
   
    return dev;
}

std::vector <advcpp::SharedPtr<Device> > DeviceLoader::Load(std::vector<DeviceConfig>& a_confVec)
{
   std::vector <advcpp::SharedPtr<Device> > devVec;

   std::vector<DeviceConfig>::const_iterator bcit = a_confVec.begin();
   std::vector<DeviceConfig>::const_iterator ecit = a_confVec.end();

   while(bcit != ecit)
   {
    advcpp::SharedPtr<Device> shDev(BuildDevice(*bcit));
    if(!!shDev)
    {
        devVec.push_back(shDev);
    }    
    ++bcit;       
   }

   return devVec; 
}
}
