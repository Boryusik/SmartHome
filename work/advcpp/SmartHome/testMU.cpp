#include "mu_test.h"
#include <iostream>
#include "common.h"

#include "HVAController.h"
#include "TempSensor.h"
#include "DeviceLoader.h"
#include "Server.h"
#include "SharedPtr.h"
#include "Device.h"
#include "ConfigFile.h"

#include <unistd.h>

using namespace advcpp;
using namespace Demo;
using namespace DevicesSmartHome;
using namespace ServerComponents;

// std::vector<DeviceConfig> getConfig()
// {
//     std::vector<DevicesSmartHome::DeviceConfig> dc_vector;

//     // sensor temperature device
//     Location loc1("room_1_a","Floor-A");
//     DeviceConfig dc1("sensor_ambient_temp", loc1 , "[Temprature-1-a]","", "units: F; lower: -5; upper:55; period: 12" ); 
//     dc_vector.push_back(dc1);

//     Location loc2("room_1_b","Floor-B");
//     DeviceConfig dc2("sensor_ambient_temp", loc2 , "[Temprature-1-b]","", "units: F; lower: -5; upper:55; period: 12" ); 
//     dc_vector.push_back(dc2);


//     // sensor temperature device   
//     DeviceConfig dc3("controller_ambient_temp", loc1, "[Ctrl_Temprature-1-a]"); 
//     dc_vector.push_back(dc3);

//     return dc_vector;
// }



UNIT(test_phase_00)   
    
//     Server srv;
//     {
//         Location location("room-1","floor-1");
//         TempSensor ts(location);
//         ts.connect(srv.getTaker());  
//         TRACER << "Sensor is ON\n";        
        
        

//         // HVAController hvac(location);
//         TRACER << "Controller is ON\n";        
//         // hvac.registrate(srv.getRegistrer());

//         sleep(4);
//         ts.shutDown();
//     }
    
//     TRACER << "Server Will shutdown!\n";
//     srv.shutDown();

//     ASSERT_THAT(true);

END_UNIT


UNIT(test_phase_1)   
    
    // Server srv;
    // TRACER << "Server is ON\n";

    // std::vector<DeviceConfig> dc = getConfig();
    // DeviceLoader ld;
    // std::vector<SharedPtr<Device> > devices  = ld.Load(dc);
    // srv.attachDevices(devices);
    
    // // Location location("room-1","floor-1");
    // // TempSensor ts(location);
    // // TRACER << "Sensor is ON\n";

    // // ts.connect(srv.getTaker());    
    // // TRACER << "Sensor is connected\n";

    // // // HVAController hvac(location);
    // // TRACER << "HVASensor is ON\n";
    
    // // // hvac.registrate(srv.getRegistrer());
    // // TRACER << "HVASensor is Registered\n";
    
    // // sleep(6);
    
    // // ts.shutDown();   

    // // sleep(2);
    // srv.shutDown();

    // ASSERT_THAT(true);

END_UNIT




UNIT(test_phase_2)   
    
    Server srv;
    TRACER << "Server is ON\n";

    ConfigFile cf("./resources/config.ini");
    std::vector<DeviceConfig> dc = cf.getConfigs();  

    DeviceLoader ld; 
    std::vector<SharedPtr<Device> > devices  = ld.Load(dc);  
   
    ASSERT_EQUAL(srv.attachDevices(devices), devices.size());  
        
    sleep(12);    
    srv.shutDown();   // shutdown srv and devices

    ASSERT_THAT(true);

END_UNIT

TEST_SUITE(base_test)

    IGNORE_TEST(test_phase_00)	  
    IGNORE_TEST(test_phase_1) 
    TEST(test_phase_2) 
  	
END_SUITE