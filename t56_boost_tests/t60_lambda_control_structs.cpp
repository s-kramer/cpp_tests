#include <iostream>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/if.hpp>
// #include <boost/bind.hpp>

using boost::lambda::_1;

int main()
{
    std::function<void(int)> printIfEven(if_then(_1 % 2 == 0, std::cout << boost::lambda::_1 ));
    printIfEven(1);
    std::cout << '\n';
    printIfEven(2);
    std::cout << '\n';
    return 0;
}
