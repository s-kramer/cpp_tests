#include <iostream>
class Base
{
public:
    Base () {};
    virtual ~Base () {};
    virtual inline void foo(void) {std::cout << "Base" << '\n';  }
    
private:
    Base (const Base&);
    Base operator=(const Base&);
};

class Derived : public Base
{ 
public:
    Derived () {};
    virtual ~Derived () {};
    virtual inline void foo(void) {std::cout << "Derived" << '\n';  }
private:
    Derived (const Derived&);
    Derived operator=(const Derived&);
};

int main()
{ 
    Base* b = new Derived;
    b->foo();
    delete b;

    b = new Base;
    b->foo();
    delete b;
    return 0;
}
