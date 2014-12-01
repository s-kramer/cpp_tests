#include <iostream>
#include <memory>

class Incremented
{
public:
    explicit Incremented (void) { count++; };
    virtual ~Incremented () { count--; };
    static unsigned getObjectCount (void ) { return count; };
        
private:
    static unsigned count;
};
unsigned Incremented::count = 0;


template<class Derived>
class Singleton
{
public:
    template<class ... ConstructorArguments>
    static std::shared_ptr<Derived> getInstance(ConstructorArguments&&... constructorArguments) 
    {
        if (p == 0) {
            /* Forward first, than unpack! */
            p = std::shared_ptr<Derived>(new Derived(std::forward<ConstructorArguments>(constructorArguments)...));
        }
        return p;
    }
    virtual ~Singleton () = default;

    /* This constructor has to be protected because the getInstance method needs to be able to construct an Instance of the Derived type. In order to do that all the constructors inherited by the Derived (SomeOtherClass in this case) need to be available. */
    /* Alternative: make the constructor private and mark the Singleton class a friend. */
protected:
    explicit Singleton (void) = default;

private:
    Singleton(const Singleton&) = delete;
    Singleton& operator = (const Singleton&) = delete;

    static std::shared_ptr<Derived> p;
};

template<class Derived>
// std::shared_ptr<Derived> Singleton<Derived>::p = static_cast<std::shared_ptr<Derived>>(0);
std::shared_ptr<Derived> Singleton<Derived>::p = nullptr;

class SomeOtherClass : public Singleton<SomeOtherClass>, public Incremented
{
    public:
        struct SomeOtherClassValues {
            SomeOtherClassValues(std::string message, int secondValue) : message_(message), secondValue_(secondValue) {};
            std::string message_; 
            int secondValue_;
        };

        SomeOtherClass() = default;
        SomeOtherClass(std::string message) : message_(message) {};
        SomeOtherClass(std::string message, int secondValue) : message_(message), secondValue_(secondValue) {};
        SomeOtherClassValues getValues(void) { return SomeOtherClassValues(message_, secondValue_); };
    private:
        std::string message_ = "default message";
        int secondValue_ = 2;
};


int main()
{
    {
        std::string message("Some message");
        std::cout << "Message creation time address: " << (void*)message.data() << '\n'; //!

        std::shared_ptr<SomeOtherClass> s1 = SomeOtherClass::getInstance(std::move(message), 10);
        SomeOtherClass::SomeOtherClassValues values = s1->getValues();
        std::cout << "Values of the first object: " << values.message_ << ", " << values.secondValue_ << '\n';
        std::cout << "Object count: " << s1->getObjectCount() << '\n';
        std::cout << "Returned message address: " << (void*)values.message_.data() << '\n';

        std::shared_ptr<SomeOtherClass> s2 = SomeOtherClass::getInstance();
        values = s2->getValues();
        std::cout << "Values of the second object: " << values.message_ << ", " << values.secondValue_ << '\n';
        std::cout << "Object count: " << s2->getObjectCount() << '\n';

        std::shared_ptr<SomeOtherClass> s3 = SomeOtherClass::getInstance();
        values = s3->getValues();
        std::cout << "Values of the third object: " << values.message_ << ", " << values.secondValue_ << '\n';
        std::cout << "Object count: " << s3->getObjectCount() << '\n';
    }
    return 0;
}
