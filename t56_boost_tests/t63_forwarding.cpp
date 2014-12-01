#include <iostream>
#include <boost/move/move.hpp>

class copyable
{
public:
    explicit copyable (void) 
    {
        std::cout << "copyable default constructor\n";
    };

    explicit copyable(int)
    {
        std::cout << "copyable int constructor\n";
    }

    copyable& operator=(const copyable &rhs)
    {
        std::cout << "copyable operator=(const copyable &rhs)\n";
        return *this;
    }
    copyable (const copyable &rhs)
    {
        std::cout << "copyable copy constructor\n";
    }

};

class copyable_and_movable
{
    BOOST_COPYABLE_AND_MOVABLE(copyable_and_movable)
public:
    explicit copyable_and_movable (void)
    {
        std::cout << "copyable_and_movable default constructor\n";
    };

    explicit copyable_and_movable (int)
    {
        std::cout << "copyable_and_movable int constructor\n";
    }

    copyable_and_movable(const copyable_and_movable &rhs)
    {
        std::cout << "copyable_and_movable copy constructor\n";
    }

    copyable_and_movable& operator=(BOOST_COPY_ASSIGN_REF(copyable_and_movable) rhs)
    {
        std::cout << "copyable_and_movable operator=(BOOST_COPY_ASSIGN_REF(copyable_and_movable)\n";
        return *this;
    }

    // Move constructor
    copyable_and_movable (BOOST_RV_REF(copyable_and_movable) rhs)
    {
        std::cout << "copyable_and_movable move constructor\n";
    }

    // Move assign operator
    copyable_and_movable& operator=(BOOST_RV_REF(copyable_and_movable) rhs)
    {
        std::cout << "copyable_and_movable move assing operator\n";
        return *this;
    }


};

template <typename MaybeMovable, typename MaybeRV>
void functionConstructor(BOOST_FWD_REF(MaybeRV) x)
{
    MaybeMovable a(boost::forward<MaybeRV>(x));
}


int main()
{
    std::cout << "Creating copyable_and_movable object c\n";
    copyable_and_movable c;
    std::cout << "Moving c object\n";
    functionConstructor<copyable_and_movable>(boost::move(c));
    std::cout << "passing newly created object\n";
    functionConstructor<copyable_and_movable>(copyable_and_movable());
    std::cout << "passing newly created object wrapped with boost::move\n";
    functionConstructor<copyable_and_movable>(boost::move(copyable_and_movable()));

    std::cout << "Creating copyable object nm\n";
    copyable nm;
    std::cout << "calling functionConstructor with nm object wrapped with boost::move (calling copy constructor\n";
    //copy constructor (copyable_only_tester has no move ctor.)
    functionConstructor<copyable>(boost::move(nm));
    std::cout << "Calling copyable copy constuctor\n";
    //copy constructor
    functionConstructor<copyable>(nm);
    std::cout << "Calling copyable int constructor\n";
    //int constructor
    functionConstructor<copyable>(int(0));

    return 0;
}

