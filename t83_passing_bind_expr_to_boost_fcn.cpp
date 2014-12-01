#include <iostream>
#include <boost/bind.hpp>
#include <boost/function.hpp>

void testFcn(int i)
{
    std::cout << i  << '\n'; 
}

class testClass
{
public:

    void testMethod(int i)
    {
        std::cout << i << '\n';
    }
};

int main()
{
    testClass t;

    boost::function<void(void)> fcn(boost::bind(&testClass::testMethod, t, 5));
    fcn();

    return 0;
}
