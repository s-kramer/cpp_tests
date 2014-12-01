#include <iostream>

class Base
{
public:
    explicit Base (void) : i(0) {};
    explicit Base (int i) : i(i) {};
    int operator++(void) { return ++i; }
    int operator++(int) { int tmp = i; ++i; return tmp; }
    int getI(void) { return i; }
    Base* clone(void) { return new Base(*this); }
private:
    int i;
};

template <typename T>
struct opNewCreator {
    static T* create(void) { return new T; }
};

template <typename T>
struct prototypeCreator {
    public:
        prototypeCreator(T* obj = 0) : obj(obj) {}
        T* create(void) { return obj? obj->clone() : 0; }

        void setObj(T* newObj) { obj = newObj; }
        T* getObj(void) { return obj; }
    private:
        T* obj;
};

template < template <typename Created> class CreationPolicy>
class BaseMgr : public CreationPolicy<Base>
{
    typedef CreationPolicy<Base> actualPolicy;

public:
    Base* create(void) { return actualPolicy::create(); }
};

typedef BaseMgr< opNewCreator > MyBaseMgr;
typedef BaseMgr< prototypeCreator > MyPrototypeBaseMgr;

int main()
{
    MyBaseMgr mbm;
    Base* b = mbm.create();
    std::cout << "b->getI: " << b->getI() << '\n';

    (*b)++;

    MyPrototypeBaseMgr mpbm;
    mpbm.setObj(b);
    Base* bp = mpbm.create();
    std::cout << "bp->getI: " << bp->getI() << '\n';

    delete b;
    delete bp;
    return 0;
}
