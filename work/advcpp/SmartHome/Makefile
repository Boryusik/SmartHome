TARGET = testMU
 # we are using g++, hence the need to define CC
CC=g++
CXX=g++
# C compiler flags
CFLAGS +=-g -pedantic -ansi -Wall -Werror  -DDEBUG
CXXFLAGS += $(CFLAGS) -std=c++03
# Linker (ld) flags
LDFLAGS+=-g -pthread -export-dynamic
LDLIBS = -ldl -lpthread
# Include path
INC_DIR += ../include ./include
INC_FLAG = $(addprefix -I,$(INC_DIR))

CPPFLAGS += $(INC_FLAG)

# all .c files in current directory
SOURCES ?= $(wildcard *.cpp) 
SOURCES += ../thread/Thread.cpp ../thread/mutex.cpp ../thread/ConditionVar.cpp 
SOURCES += ../sharedPtr/Counter.cpp
SOURCES += ../ThreadPoolExecutor/ThreadPoolExecutor.cpp
SOURCES += ./Demo/HVAController.cpp ./Demo/TempSensor.cpp ./Demo/TempEvent.cpp
SOURCES += ./DevicesSmartHome/Device.cpp
SOURCES += ./DevicesSmartHome/DeviceConfig.cpp 
SOURCES += ./DevicesSmartHome/EventController.cpp 
SOURCES += ./DevicesSmartHome/EventSensor.cpp
SOURCES += ./ServerComponents/BuilderSo.cpp
SOURCES += ./ServerComponents/ConfigFile.cpp
SOURCES += ./ServerComponents/DeviceLoader.cpp
SOURCES += ./ServerComponents/EventManager.cpp 
SOURCES += ./ServerComponents/Register.cpp 
SOURCES += ./ServerComponents/Router.cpp
SOURCES += ./ServerComponents/Server.cpp
SOURCES += ./ServerComponents/SThrdDispetcher.cpp 
SOURCES += ./GeneralSmartHome/Event.cpp 


OBJECTS ?= $(SOURCES:.cpp=.o)
#
.PHONY: all clean test
#

all: $(TARGET) test

# the target is the test file
#	Built-in linker rule $(CC) $(LDFLAGS) -o $(@) $(*) $(LDLIBS)
$(TARGET): $(OBJECTS)


# dependencies
# for every line in depends file the following built-in rule is used
# $(CC) $(CPPFLAGS) $(CFLAGS) / $(CXXFLAGS) -c -o $@ $<
include depends
depends:
	$(CC) -MM $(CPPFLAGS) $(SOURCES) > depends

clean:
	rm -f $(OBJECTS) $(TARGET)  depends *.gch *.ppm

test: $(TARGET) 
	./$(TARGET) -v
	#valgrind --tool=drd  --log-file=log1.txt ./testMU

