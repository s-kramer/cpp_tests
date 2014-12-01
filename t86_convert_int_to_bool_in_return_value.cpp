#include <iostream>

bool predicate(void)
{
    return 5;
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << predicate() << '\n';
    predicate();
    return 0;
}
