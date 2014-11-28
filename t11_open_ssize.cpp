#include <iostream>
#include <inttypes.h>

int main(int argc, char const *argv[])
{
    std::cout << sizeof(uint32_t) << " " << (static_cast <ssize_t> (sizeof (uint32_t)));

    return 0;
}
