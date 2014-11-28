#include <iostream>

class Base
{
  public:
    explicit Base(void){};
    virtual ~Base(){};
    int b;

  protected:
    Base(const Base &base) { b = base.b; };
    Base operator=(const Base &);
};

class Derived : public Base
{
  public:
    explicit Derived(void){};
    int d;

  private:
};

int main()
{
    // This slices the Derived object to Base class only.
    // Copy is not possible becouse of the protected copy ctor.
    // b.d is not accessible becouse of the slicing.
    // Derived* dp = new Derived;
    // Base b(*dp);
    // b.d;

    // This acts as desired but requires defining Base's copy ctor./ Each Base
    // class should declare it's copy assignment operator and copy constructor
    // protected.
    Derived *dp = new Derived;
    Derived derived(*dp);
    derived.d;
    return 0;
}
