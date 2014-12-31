#ifndef SERIALPORT_H
#define SERIALPORT_H
#include <string>
#include <boost/asio.hpp>

class SerialPort
{
    public:
        explicit SerialPort (const std::string& portName, unsigned int baudrate);
        ~SerialPort ();
        std::size_t write(std::string buffer);
        std::string readLine();

private:
    boost::asio::io_service io_service;
    boost::asio::serial_port serialPort;

};

#endif /* end of include guard: SERIALPORT_H */

