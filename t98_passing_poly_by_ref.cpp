#include <iostream>
class Foo
{
  public:
    explicit Foo(void){};
    virtual ~Foo(){};

    int i;
    virtual void print(void) const { std::cout << "Foo::i" << '\n'; }

  private:
    Foo(const Foo&);
    Foo operator=(const Foo&);
};

class Bar : public Foo
{
  public:
    explicit Bar(void){};
    virtual ~Bar(){};

    virtual void print(void) const override
    {
        std::cout << "Bar::i" << '\n';
    }

  private:
    Bar(const Bar&);
    Bar operator=(const Bar&);
};

void boo(const Foo& f)
{
    f.print();
}

int main()
{
    Foo f;
    Bar b;

    boo(f);
    boo(b);

    // Prints: 
    // Foo::i
    // Bar::i
    // Reference doesn't affect polymorphism just as pointers.
    return 0;
}

