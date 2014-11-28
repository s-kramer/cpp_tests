#include <iostream>
#include <sstream>
#include <iomanip>  // std::setfill, std::setw
#include <bitset>



int main(int argc, char const *argv[])
{
    std::stringstream stream;
    if (argc == 1)
        return 0;
    stream << std::setw (32) << std::setfill ('0') << std::bitset <32> (std::stoi (argv[1])).to_string();
    std::cout << stream.str();

    return 0;
}
