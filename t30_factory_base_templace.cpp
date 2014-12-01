#include <iostream>
#include <map>
/*
 * The BaseFactory class is the main class to demonstrate the above idea. A specialized type of factory instance for some Product type 
 * hierarchy can be created as below:
 * 
 * BaseFactory<Product> productFactory;
 * 
 * To register a new Product type:
 * 
 * productFactory.RegisterType<P1>("P1");
 * 
 * To create instance of a Product type:
 * 
 * Product* product = productFactory.CreateInstance("P1");
 */
template<class T>
class BaseFactory
{
public:
    T *CreateInstance(std::string typeName)
    {
        typename TypeMap::iterator it = mTypeMap.find(typeName); 

        if ( it != mTypeMap.end())
        {
            return it->second();
        }
 
        return NULL;
    } 
 
    template<class DerivedT> 
   
    void RegisterType(std::string derivedTypeName)
    {
        this->mTypeMap[derivedTypeName] = &BaseFactory<T>::CreateT<DerivedT>;
    }

private:
    // This should use shared ptrs
    typedef std::map<std::string, T *(*)()> TypeMap;
    TypeMap mTypeMap;
    template<class DerivedT>
    static T* CreateT() { return new DerivedT; }
};

class Base
{
public:
    explicit Base (void) {};
    virtual ~Base () {};
    virtual std::string identify(void) {return std::string("Base class");};

private:
    
};

class Derived : public Base
{
public:
    explicit Derived (void) {};
    virtual ~Derived () {};
    virtual std::string identify(void) {return std::string("Derived class");};

private:
    
};

int main()
{
    BaseFactory<Base> f;
    f.RegisterType<Derived>("Derived");
    Base* bptr = f.CreateInstance("Derived");
    std::cout << bptr->identify() << '\n';
    
    return 0;
}
