#include <iostream>
#include <boost/move/move.hpp>
#include <boost/container/vector.hpp>
#include <vector>

class LargeClass
{
public:
    explicit LargeClass (void): numbers(20, 10) 
    {
    }
    LargeClass (const LargeClass &rhs): numbers(rhs.numbers)
    { 
        std::cout << "Using LargeClass copy constructor" << '\n';
    }
    LargeClass (LargeClass &&rhs): numbers(boost::move(rhs.numbers))
    { 
        std::cout << "Using LargeClass move constructor" << '\n';
    }

    const int* getNumbersAddress(void) const
    {
        return &(numbers.front());
    }
    
private:
    boost::container::vector<int> numbers;
};

int main()
{
    LargeClass l1;
    std::cout << "l1 vector address: " << l1.getNumbersAddress() << '\n';

    LargeClass l2(l1);
    std::cout << "l1 vector address: " << l1.getNumbersAddress() << '\n';
    std::cout << "l2 vector address: " << l2.getNumbersAddress() << '\n';

    LargeClass l3 = std::move(l2); 
    std::cout << "l1 vector address: " << l1.getNumbersAddress() << '\n';
    std::cout << "l2 vector address: " << l2.getNumbersAddress() << '\n';
    std::cout << "l3 vector address: " << l3.getNumbersAddress() << '\n';

    return 0;
}
