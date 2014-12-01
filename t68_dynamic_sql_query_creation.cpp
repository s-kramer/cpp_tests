#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

int main(int argc, char *argv[])
{
    // std::vector<std::string> hello(3, "Hello World");
    std::vector<std::string> hello;
    std::copy(argv + 1, argv + argc, std::back_inserter(hello));

    std::cout << "\'";
    std::copy(hello.begin(), hello.end() - 1, std::ostream_iterator<std::string>(std::cout, "', '"));

    std::cout << hello.back() << "\'" << '\n';

    return 0;
}
