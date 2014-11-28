#include <iostream>
#include <sstream>

int main()
{
    std::stringstream ss("");
    ss << 3;
    int num;
    std::cout << "ss:  " << ss.str() << '\n';
    ss >> num;
    std::cout << "num: " << num << '\n';
    std::cout << "ss:  " << ss.str() << '\n';
    return 0;
}
