#include <iostream>
#include <typeinfo>

class A
{
public:
    explicit A (int a): _a(a) {
        std::cout << "A: " << _a << '\n';
    }
    virtual ~A ()
    {
        std::cout << "destuctor or A: " << '\n';
    };

    virtual void print (void)
    {
        std::cout<< "print method of A: " << _a << '\n';
    }
private:
    int _a;
};

class B : public A
{
public:
    using A::A;
    explicit B () : A(5) {
        std::cout << "B default constructor" << '\n';
        print();
    }

    virtual void print (void)
    {
        std::cout<< "print method of B: " << '\n';
    }
    virtual ~B () 
    {
        std::cout << "destuctor or B: " << '\n';
    };
};
int main()
{
    B b;

    B ba(10);

    b.print();
    ba.print();

    std::cout << typeid(ba).name() << '\n';
    return 0;
}
