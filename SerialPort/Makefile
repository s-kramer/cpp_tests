CC=g++
CFLAGS=-c -Wall -static 
LDFLAGS=-static -lboost_system -dynamic -lpthread 
SOURCES=t54_boost_asio.cpp SerialPort.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=t54_boost_asio

ifeq ($(CROSS),1)
    CROSS_COMPILE = arm-linux-gnueabihf-
endif

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CROSS_COMPILE)$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CROSS_COMPILE)$(CC) $(CFLAGS) $< -o $@ 

clean:
	rm $(EXECUTABLE) *.o
