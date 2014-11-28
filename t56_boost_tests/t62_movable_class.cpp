#include <iostream>
#include <boost/move/move.hpp>
#include <boost/container/vector.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm_ext/iota.hpp>
#include <vector>

typedef boost::container::vector<int> bvector;

class MovableClass
{
    private:
        BOOST_COPYABLE_AND_MOVABLE(MovableClass)
    public:
        explicit MovableClass (unsigned numberCount = 10): numbers(numberCount) 
        {
            boost::range::iota(this->numbers, 0);
        }

        MovableClass (const MovableClass &rhs): numbers(rhs.numbers)
        { }

        MovableClass& operator=(BOOST_COPY_ASSIGN_REF(MovableClass) rhs)
        {
            if (this != &rhs) {
                boost::container::vector<int> tmp = rhs.numbers;
                numbers = boost::move(tmp);
            }
            return *this;
        }
        
        MovableClass(BOOST_RV_REF(MovableClass) rhs): numbers(boost::move(rhs.numbers))
        { }

        MovableClass& operator=(BOOST_RV_REF(MovableClass) rhs)
        {
            numbers = boost::move(rhs.numbers);
            rhs.numbers.empty();
            return *this;
        }

    const int* getNumbersAddress(void) const
    {
        return numbers.data();
    }
    private:
        boost::container::vector<int> numbers;
};

int main()
{
    MovableClass m1, m4;
    std::cout << "Starting situation: \n";
    std::cout << "m1 vector address: " << m1.getNumbersAddress() << '\n';
    std::cout << "m4 vector address: " << m4.getNumbersAddress() << '\n';
    std::cout << '\n';

    MovableClass m2(m1);
    std::cout << "m2 copy constructed from m1:\n";
    std::cout << "m1 vector address: " << m1.getNumbersAddress() << '\n';
    std::cout << "m2 vector address: " << m2.getNumbersAddress() << '\n';
    std::cout << "m4 vector address: " << m4.getNumbersAddress() << '\n';
    std::cout << '\n';

    m1 = m4;
    std::cout << "m1 copy assigned m4's value:\n";
    std::cout << "m1 vector address: " << m1.getNumbersAddress() << '\n';
    std::cout << "m2 vector address: " << m2.getNumbersAddress() << '\n';
    std::cout << "m4 vector address: " << m4.getNumbersAddress() << '\n';
    std::cout << '\n';

    MovableClass m3 = boost::move(m2); 
    std::cout << "m3 move constructed from m2:\n";
    std::cout << "m1 vector address: " << m1.getNumbersAddress() << '\n';
    std::cout << "m2 vector address: " << m2.getNumbersAddress() << '\n';
    std::cout << "m3 vector address: " << m3.getNumbersAddress() << '\n';
    std::cout << "m4 vector address: " << m4.getNumbersAddress() << '\n';
    std::cout << '\n';

    m3 = boost::move(m1);
    std::cout << "m3 move assigned from m1:\n";
    std::cout << "m1 vector address: " << m1.getNumbersAddress() << '\n';
    std::cout << "m2 vector address: " << m2.getNumbersAddress() << '\n';
    std::cout << "m3 vector address: " << m3.getNumbersAddress() << '\n';
    std::cout << "m4 vector address: " << m4.getNumbersAddress() << '\n';
    std::cout << '\n';

    return 0;
}

