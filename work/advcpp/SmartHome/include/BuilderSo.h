#ifndef BUILDER_SO_H
#define BUILDER_SO_H
#include "common.h"
#include "SharedPtr.h"
#include "Device.h"

namespace ServerComponents{

class BuilderSo
{
public:
    BuilderSo(devType const& a_type);
    advcpp::SharedPtr<DevicesSmartHome::Device> makeDevice(DevicesSmartHome::DeviceConfig const&);

private:
    void*        m_handle;
};

}

#endif


