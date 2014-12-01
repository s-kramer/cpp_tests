#include <iostream>
#include <iterator>
#include <boost/iterator/counting_iterator.hpp>
#include <vector>

class FibIterator : public std::iterator<std::input_iterator_tag, int>
{
public:
    explicit FibIterator(unsigned int max) : max(max)
    {
        prev1 = 0;
        prev2 = 0;
        actual = 1;

        prevVals.push_back(1);
        prevVals.push_back(1);
    }

    FibIterator(const FibIterator& rhs)
    {
        actual = rhs.actual;
        prev1 = rhs.prev1;
    }

    FibIterator& operator=(const FibIterator& rhs)
    {
        actual = rhs.actual;
        prev1 = rhs.prev1;
        return *this;
    }

    FibIterator& operator++(void)
    {
        if (actual >= max) {
            return *this;
        }

        prev2 = prev1;
        prev1 = actual;
        actual += prev2;
        return *this;
    }

    FibIterator operator++(int)
    {
        FibIterator temp(*this);
        ++temp;
        return temp;
    }

    unsigned operator*() const
    {
        return actual;
    }

    bool operator==(const FibIterator& rhs) const
    {
        return rhs.actual == actual;
    }

    bool operator!=(const FibIterator& rhs) const
    {
        return !operator==(rhs);
    }


private:
    unsigned int max;
    unsigned int prev1, prev2;
    unsigned int actual;
    static std::vector<int> prevVals;
    static int prevValsIndex;
};

int FibIterator::prevValsIndex = 0;
//todo: dokonczyc dodawanie vektora statycznego


int main()
{
    FibIterator begin(100);

    std::cout << *begin << '\n';
    std::cout << *(++begin) << '\n';
    std::cout << *(++begin) << '\n';
    std::cout << *(++begin) << '\n';
    std::cout << *(++begin) << '\n';
    std::cout << *(++begin) << '\n';
    std::cout << *(++begin) << '\n';
    std::cout << *(++begin) << '\n';
    
    return 0;
}
