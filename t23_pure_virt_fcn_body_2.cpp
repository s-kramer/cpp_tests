#include <iostream>
#include <boost/scoped_ptr.hpp>

class Base
{
public:
    explicit Base (void) {};
    ~Base () {};
    virtual void identify(void) = 0;
private:
    
};
void Base::identify()
{
    std::cout << "Abstract Base class pure function body here.\n";
}

class Derived : public Base
{
public:
    explicit Derived (void) {};
    ~Derived () {};
    virtual void identify(void){ std::cout << "Derived class pure fcn implementation.\n";};

    
};

int main()
{
    boost::scoped_ptr<Base> ptr(new Derived);
    ptr->Base::identify();
    return 0;
}

