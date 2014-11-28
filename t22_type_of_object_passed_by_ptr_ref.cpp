#include <iostream>
class Base
{
public:
    explicit Base (void) {};
    /* 
     * Virtual base class destructor inherited by all the derived classes. 
     * They don't have to implement their own constructors - compiler default 
     * destructor is already virtual.
     */
    virtual~Base () { std::cout << "~Base\n"; };

    virtual void Identify (void) const { std::cout << "Base class\n"; };
};

class Derived : public Base
{
public:
    explicit Derived (void) {};
    // virtual ~Derived ();
    virtual void Identify(void) const { std::cout << "Derived class\n"; };
};

void pass_by_ptr (Base * const ptr)
{
    std::cout << "Passed by ptr\n";
    ptr->Identify();
}

/* 
 * Pass by reference behaves the same as pass by pointer as long as inheritance 
 * is considered, i.e. reference to a Base class is may contain an object of the 
 * derived class and call all the virtuall methods correctly.
 */
void pass_by_ref (const Base &ref)
{
    std::cout << "Passed by ref\n";
    ref.Identify();
}
int main()
{
    Base b;
    Derived d;

    pass_by_ptr(&b);
    pass_by_ptr(&d);

    pass_by_ref(b);
    pass_by_ref(d);

    return 0;
}
