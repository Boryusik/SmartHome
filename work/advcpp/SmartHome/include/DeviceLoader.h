#ifndef DEVICE_LOADER_H
#define DEVICE_LOADER_H

#include "common.h"
#include "DeviceConfig.h"
#include "Device.h"
#include "SharedPtr.h"
#include "TempSensor.h"
#include "HVAController.h"

namespace ServerComponents{


typedef std::vector<advcpp::SharedPtr<DevicesSmartHome::Device> > DeviceVec;

class DeviceLoader
{
public:
    DeviceLoader();
    DeviceVec Load(std::vector<DevicesSmartHome::DeviceConfig> &a_confVec);
private:
    advcpp::SharedPtr<DevicesSmartHome::Device> BuildDevice(DevicesSmartHome::DeviceConfig const& a_dConf);
};

}

#endif