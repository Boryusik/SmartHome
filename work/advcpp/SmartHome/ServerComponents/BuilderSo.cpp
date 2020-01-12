#include "BuilderSo.h"
#include <iostream>
#include <dlfcn.h>

namespace ServerComponents{

using DevicesSmartHome::DeviceConfig;
using DevicesSmartHome::Device;
using namespace advcpp;

BuilderSo::BuilderSo(devType const& a_type)
{  
    std::string libName = "./SharedObjects/lib_" + a_type + ".so";
    m_handle = dlopen(libName.c_str(),RTLD_LAZY);

    if(m_handle == 0)
    {
        std::cout << dlerror() << a_type << "\n";
    }    

}

advcpp::SharedPtr<Device> BuilderSo::makeDevice(DeviceConfig const& a_conf)
{
    typedef SharedPtr<Device> (*MakeDevice)(DeviceConfig const& a_conf);
    advcpp::SharedPtr<Device> dev;


    MakeDevice md = reinterpret_cast<MakeDevice>(dlsym(m_handle, "MakeDevice"));

    return md(a_conf);
}

}