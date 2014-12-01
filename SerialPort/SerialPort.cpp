#include "SerialPort.h"

SerialPort::SerialPort(const std::string& portName, unsigned int baudrate = 115200) :
    io_service(),
    serialPort (io_service, portName)
{
    serialPort.set_option(boost::asio::serial_port::baud_rate(baudrate));
}
            
SerialPort::~SerialPort()
{
    serialPort.close();
}

std::size_t SerialPort::write(std::string buffer)
{
    return serialPort.write_some(boost::asio::buffer(buffer.data(), buffer.size()));
}

std::string SerialPort::readLine()
{
    std::string result;
    char c;

    while (1) {
        serialPort.read_some(boost::asio::buffer(&c, 1));
        switch (c) {
            case '\r': 
                break;

            case '\n':
                return result;

            default:
                result.append(1, c);
                break;
        }
        
    }
}
