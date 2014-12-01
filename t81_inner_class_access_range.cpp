#include <iostream>

class Outer
{
public:
    Outer (void) {};

    void print_sth(void) { std::cout << "Outer print" << '\n'; }
    
private:
    class Inner
    {
    public:
        Inner (Outer& outer) : outer(outer) {};
        void inner_print(void) { outer.print_sth(); }
        
    private:
        Outer& outer;
    };
};

