#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<int> v (10,0);
    for (auto i : v)
    {
        std::cout << i << '\n';
        std::cout << " " << &i << '\n';
    }

    for (auto i = v.cbegin(); i != v.cend(); i++)
        std::cout << *i << " " << &i << '\n';
    return 0;
}
