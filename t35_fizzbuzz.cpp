#include <iostream>

int main()
{
    for (int i = 1; i < 101; i++) {
        bool mult = false;
        if (!(i % 3)) {
            std::cout << "Fizz";
            mult = true;
        }
        if (!(i % 5)) {
            std::cout << "Buzz";
            mult = true;
        }
        if (!mult) {
            std::cout << i;
        }
        std::cout << '\n';
    }
    return 0;
}
