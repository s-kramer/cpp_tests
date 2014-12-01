#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>  // std::setfill, std::setw

const char* int_to_hex (std::string i, int width = 2)
{
    //std::cout << std::setw(4) << std::setfill('0') << std::hex << ((htobe16 (std::strtol (argv[1], NULL, 10))) >> 4) << '\n';
    static std::stringstream stream;
    stream.str("");
    stream << std::setw (width) << std::hex << htobe32 (*(i.c_str())); 
    return stream.str().c_str();
}

const char* hex_to_int (std::string i, int width = 3)
{
    //uint32_t figure32 = htobe32 (std::strtol (argv[1], NULL, 10));
    //std::cout << std::setw (16) << std::setfill ('0') << std::hex << std::strtol (argv[1], NULL, 10) << '\n';
    //std::cout << std::setw (3) << std::dec << be64toh (figure64) << '\n';
    //std::cout << std::hex <<  figure32 << '\n';
    //std::cout << std::setw (16) << std::setfill ('0') << be32toh (figure32) << '\n';

    static std::stringstream stream;
    stream.str("");
    stream << std::setw (width) << std::dec << be32toh (*(i.c_str())) << '\n';
    return stream.str().c_str();
}

int main(int argc, char const *argv[])
{
    int a = 100, b = 15;
    

    std::cout << int_to_hex (std::to_string (a)) << " " << int_to_hex (std::to_string (b)) << '\n';

    //std::stringstream ss ("example string");
    //std::cout << ss.str() << '\n';
    //std::string str (std::to_string (a));
    //ss.str (std::to_string (a) + " " + std::to_string (b) + '\n');
    //std::cout << ss.str() << '\n';
    return 0;
}
