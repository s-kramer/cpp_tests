#include "counterMPL.hpp"
#include <iostream>
#include <ostream>

int main()
{
    CounterMPL<10> c;
    CounterMPL<300> cf;
    for (int i = 0; i < 20; i++) {
        ++c;
        std::cout << (int)c.getValue() << '\n';
    }

    for (int i = 0; i < 310; i++) {
        ++cf;
        std::cout << (int)cf.getValue() << '\n';
    }
    return 0;
}
