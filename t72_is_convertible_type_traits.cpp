#include <iostream>
#include <type_traits>

class Base {};
class Derived : public Base {};

int main()
{
    std::cout << std::boolalpha;
    std::cout << "Derived to Base: " << std::is_convertible<Derived, Base>::value << '\n';
    std::cout << "Int to Base: " << std::is_convertible<int, Base>::value << '\n';
    return 0;
}
