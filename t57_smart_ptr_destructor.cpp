#include <iostream>
#include <boost/smart_ptr.hpp>

struct B {
    int i = 5;
};

struct D : public B {
    ~D() { std::cout << "D`s destructor\n"; }
};

int main()
{
    // D d;
    // std::auto_ptr<B> pa(new D);
    boost::shared_array<B> ps(new D);
    return 0;
}
