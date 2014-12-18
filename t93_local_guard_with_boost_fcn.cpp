#include <iostream>
#include <boost/function.hpp>
#include <boost/bind.hpp>

class foo
{
public:
    explicit foo (boost::function<void(void)> f) : func(f), active(true) {};
    ~foo() { if(active) { func(); } };
    void deactivate(void) { active = false; }
    
private:
    boost::function<void(void)> func;
    bool active;
};

void bar(int i)
{
    std::cout << "Function called by guard here: " << i << '\n'; 
}

int main()
{
    foo f(boost::bind(&bar, 5));
    std::cout << "Inside of main, guard to be actiaved" << '\n';  

    // optional
    // f.deactivate();
    std::cout << "After deactivation here" << '\n'; 
    return 0;
}
