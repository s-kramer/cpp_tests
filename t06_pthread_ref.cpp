#include <iostream>
#include <thread>

class Reference_passing_test
{
public:
    Reference_passing_test (int i):
        _i (i)
    {
    };
    virtual ~Reference_passing_test ()
    {}
    void print_i(void)
    {
        std::cout << "In Reference_passing_test print_i function with argument " << this->_i << '\n';
    }

    static void print_static (Reference_passing_test *ref)
    {
        std::cout << "In Reference_passing_test::print_static\n";
        ref->print_i();
    }

private:
    int _i;
};

void print(void)
{
    std::cout << "In a thread\n";
}

void print_2(int i)
{
    std::cout << "In the second thread with argument " << i << '\n';
}

void pass_reference (Reference_passing_test* ref)
{
    ref->print_i();
}

int main()
{
    Reference_passing_test reference_passing_test(5);

    std::thread t1 (print);
    std::thread t2 (print_2, 5);
    std::thread t3 (pass_reference, &reference_passing_test);
    std::thread t4 (Reference_passing_test::print_static, &reference_passing_test);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    
    return 0;
}
