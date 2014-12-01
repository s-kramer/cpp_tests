#include <iostream>
// #include <boost/bind.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/lambda/construct.hpp>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

class Foo
{
public:
    explicit Foo (std::string str) : length(str.length()) {};
    bool isStringEven(void) const { return length % 2 == 0; }
private:
    int length;
};


int main()
{
    std::vector<std::string> vs;
    vs.push_back("qwerty");
    vs.push_back("ab");

    std::vector<std::string> result;

    using namespace boost::lambda;
    // It's not possible to take the address of an constructor.
    // Therefore, this approach is not correct.
    // std::remove_if(vs.begin(), vs.end(), bind(&Foo::isStringEven, 
                // bind(&Foo::Foo, _1)
                // ));

    // Create objects
    std::vector<Foo> FooContainer;
    std::transform(vs.begin(), vs.end(), std::back_inserter(FooContainer), bind<Foo>(constructor<Foo>(), _1));

    // Display those objects
    std::cout << std::boolalpha;
    std::transform(FooContainer.begin(), FooContainer.end(), std::ostream_iterator<bool>(std::cout, " "), bind(&Foo::isStringEven, _1));

    // This creates temporary objects, evaluates them (isStringEven), and prints them out to stdout.
    std::transform(vs.begin(), vs.end(), std::ostream_iterator<bool>(std::cout, " "), bind<bool>(&Foo::isStringEven, bind<Foo>(constructor<Foo>(), _1)));
    return 0;
}
