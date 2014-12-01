#include <iostream>
#include <boost/shared_ptr.hpp>
#include <memory>
#include <tr1/memory>

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
    boost::shared_ptr<Base> ptr(new Derived);
    ptr->Base::identify();
    std::shared_ptr<Base> ptr_std(new Derived);
    ptr_std->Base::identify();
    std::tr1::shared_ptr<Base> ptr_tr1(new Derived);
    ptr_tr1->identify();
    return 0;
}
