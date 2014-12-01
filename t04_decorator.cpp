#include <iostream>

/* ToDo: need to update compiler, compiles at gcc4.8.3, not working at 4.7.2 (skramer, Tue 31 Dec 2013 07:58:06 PM CET) */
template <class T>
class Decorator : public T
{
    using T::T;
    virtual void func (void)
    {
        std::cout << "Decorator message\n";
        T::func();
    }
};

class T4
{
public:
    explicit T4 (int i):
    //T4 ()
        _i (i)
    {
        
    }
    virtual ~T4 ()
    {
        
    }
    virtual void func()
    {
        return;
    }

private:
    int _i;
};

int main(int argc, char const *argv[])
{
    T4 *t4 = new Decorator<T4> (1);
    t4->func();
    t4->func();
    return 0;
}
