#include "SerialPort.h"
#include <iostream>
#include <string>

int main(int argc, const char* argv[])
{
    std::string portName;

    if (argc >= 2) {
        portName = argv[1];
    }
    else {
        portName = "/dev/ttyUSB1";
    }

    SerialPort serialPort(portName, 115200);
    while (1) {
        serialPort.write("t54_boost_asio test string\n");
    }
    return 0;
}
