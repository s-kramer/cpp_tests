#include <iostream>

class Base
{
public:
    explicit Base (void) = default;
    virtual ~Base ()  = default;
    Base (const Base &) = default;
    Base& operator=(const Base &) = default;
    virtual void identify(void) { std::cout << "Base class\n";}
    void another_identify(void) { std::cout << "Another identify\n";}
private:

};

class Derived : public Base
{
public:
    // explicit Derived (void){}
    // virtual ~Derived () {}
    virtual void identify(void) { std::cout << "Derived class\n";}
    void yet_another_identify(void) { std::cout << "Yet another identify\n";}

private:
    
};

int main()
{
    Base b;
    Derived d;
    b = d;
    b.another_identify();
    // b.yet_another_identify();
    d.another_identify();
    d.yet_another_identify();
    return 0;
}
