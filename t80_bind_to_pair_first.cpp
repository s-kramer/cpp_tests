#include <iostream>
#include <utility>
#include <boost/bind.hpp>

std::pair<bool, int> returnPair(bool b, int i)
{
    return std::make_pair(b, i);
}

int main()
{
    typedef std::pair<bool, int> myPair;
    std::cout << "integer from the pair is: " << boost::bind(&myPair::second, returnPair(true, 5))() << '\n';;
}
