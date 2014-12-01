#include "counterMPL.hpp"
#include <iostream>
#include <ostream>

int main()
{
    Counter_impl<10, true> c;
    Counter_impl<10, false> cf;
    for (int i = 0; i < 20; i++) {
        ++c;
        std::cout << (int)c.getValue() << '\n';
    }
    return 0;
}
