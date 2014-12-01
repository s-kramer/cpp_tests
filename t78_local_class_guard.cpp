#include <iostream>

int main()
{
    struct LocalGuard
    {
        ~LocalGuard() { std::cout << "guard destroyed" << '\n'; }
    } localGuard;

    if (1) {
        std::cout << "some operation" << '\n';
        if (1) {
            std::cout << "some more operation" << '\n';
            if (1) {
                std::cout << "unexpected return here" << '\n';
                return 1;
            }
        }

    }
    return 0;
}
