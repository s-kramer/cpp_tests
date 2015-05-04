#include <iostream>

class Singleton
{
    private:
        Singleton() = default;
    public:
        virtual ~Singleton() = default;
        static Singleton instanece()
        {
            static Singleton s;
            return s;
        }
};

class SingletonDerivative : public Singleton
{
    public:
        // This doesn't compile because of Singleton's private default constructor
        // SingletonDerivative() : Singleton() {}
        ~SingletonDerivative() {}
};

class Foo
{
    public:
        virtual ~Foo() = default;
    private:
        void somePrivateMethod() {};
};

class Bar : public Foo
{
    public:
        void somePrivateMethod() {}
};

int main()
{
    Foo f;
    // f.somePrivateMethod(); 
    Bar b;
    b.somePrivateMethod();
    return 0;
}
