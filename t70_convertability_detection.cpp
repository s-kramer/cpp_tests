#include <iostream>

class Base {};

class Derived : public Base {};

bool convertable(...) {
    std::cout << "Generic conversion activated" << '\n';
    return false;
}

bool convertable(Base) {
    std::cout << "Derived conversion activated" << '\n';
    return true;
}

int main() {
    // This approach requires an actual object to be created and copied
    // to the test function. The sizeof approach doesn't require an object to
    // be created, but is vulnerable to objects size.
    int ip = 0;
    Derived dp;
    std::cout << std::boolalpha;
    std::cout << "Derived to Base conversion: " << convertable(dp) << '\n';
    std::cout << "int to Base conversion: " << convertable(ip) << '\n';
    return 0;
}
