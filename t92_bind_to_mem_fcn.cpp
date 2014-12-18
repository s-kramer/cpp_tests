#include <iostream>
#include <boost/bind.hpp>

class Foo
{
public:
    void bar(int i) { std::cout <<  i << '\n'; }
};

int main()
{
    Foo f;
    boost::bind(&Foo::bar, f, _1)(5);
    return 0;
}
