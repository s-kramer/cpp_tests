#include <iostream>

template <typename T>
void fooPrinter(T rhs)
{
    std::cout << "Global fooPrinter: " << rhs << '\n';
}
void fooPrinterNonInline(int rhs)
{
    std::cout << "Global fooPrinterNonInline: " << rhs << '\n';
}

class Foo
{
public:
    Foo(void) : privateInt(2) {};
    friend void friendedPrinter(const Foo& f, int rhs) 
    {
        std::cout << "friendedPrinter: " << rhs << '\n';
        std::cout << "privateInt: " << f.privateInt << '\n';
    }
    friend void fooPrinterNonInline(int dummy);
    friend void fooPrinter(int dummy)
    {
        std::cout << "Foo friend fooPrinter: " << dummy << '\n';
    }

    void printNonInline(int rhs)
    {
        std::cout << "Foo::printNonInline" << '\n';
        fooPrinterNonInline(rhs);
    }

    void print(int rhs)
    {
        std::cout << "Foo::print" << '\n';
        fooPrinter(rhs);
    }
    
private:
    int privateInt;
};

int main()
{
    Foo f;
    f.print(5);
    f.printNonInline(10);

    friendedPrinter(f, 15);
    return 0;
}
