#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class Constructor_delegation_base
{
public:
    explicit Constructor_delegation_base (int value) : value_(value) {};
    explicit Constructor_delegation_base (void);
    virtual ~Constructor_delegation_base() {};
    virtual int get_baseclass_value(void) {return value_;};
    // This will return uninitialized (random) value
    virtual int get_uninitialized_value(void) {return not_initialized;};
private:
    int value_, not_initialized;
};

// The initializer list may be moved to the implementation file using new syntax, default parameter doesn't have to be binded to interface any more.
Constructor_delegation_base::Constructor_delegation_base (void) : Constructor_delegation_base(42) {};

class Constructor_delegation_derived : public Constructor_delegation_base
{
public:
    // Constructor inheretance. All the constructors call the base class constructors and default-initialize all the fields.
    // This class can't declare any other constructors though.
    using Constructor_delegation_base::Constructor_delegation_base;
    // Constructor_delegation_derived(int another_val, int yet_another_val) : another_val_(another_val), yet_another_val_(yet_another_val) {};
    virtual int get_baseclass_value(void)  override final { return 151;};
    int get_derivedclass_val(void) { return another_val_; };
    int get_yet_derivedclass_val(void) { return yet_another_val_; };
private:
    // Default field values
    int another_val_ = 5;
    int yet_another_val_ = 6;
};

class Lambda_test
{
public:
    void print_value(void)
    {
        // Initializer list for nearly all types, not only PODs (aggregates?)
        std::vector<int> v{4,5,6,7};
        unsigned total = 0;
        // For each algorithm and lambda expressions, (this refers to this class)
        for_each(v.begin(), v.end(), [&total, this](const int i)  { total += i + get_five(); });
        std::cout << "total: " << total << '\n';
    }
private:
        unsigned get_five(){ return 5; };
};

// Initializer list type 
void print_vector(std::initializer_list<int> list)
{
    std::for_each(list.begin(), list.end(), [](const int &i) {std::cout << i << ", ";});
    std::cout << '\n';
    std::copy(list.begin(), list.end(), std::ostream_iterator<int>(std::cout, "\n"));
    std::cout << '\n';
}

// auto move_vector (void) -> decltype(v)
std::vector<int> move_vector (void) 
{
    std::vector<int> v{3,4,5,6,7,8,9};
    std::cout << "vector's address in the function: " << &v << '\n';
    std::cout << "vector's first element address in the function is: " << &v[0] << '\n';
    return v;
}

int main()
{
    std::cout << "Vector initialized by initializer_list printed twice:\n";
    print_vector({1, 2, 3, 4, 5});
    // Single element vector
    std::vector<int> v{4};
    // Another for loop, this one traverses over a container
    std::cout << "Vector's v contents using new for:\n";
    for(auto &i : v)
    {
        std::cout << i << '\n';
    }

    Lambda_test l;
    std::cout << "Lambra_test print_value function\n";
    l.print_value();

    // Lambda functions may be captured and implicitly converted to fptrs.
    auto a_lambda_func = [](int x) { std::cout << x << '\n'; };
    void (* func_ptr)(int) = a_lambda_func;
    std::cout << "Lambda function casted to fptr:\n";
    func_ptr(4); //calls the lambda.

    Constructor_delegation_derived a;
    
    std::cout << "a.get_baseclass_value():\n";
    std::cout << a.get_baseclass_value() << '\n';

    std::cout << U"Unicode character 2018 \U00002018" << '\n';
    std::cout << u8"This is a Unicode Character: \u2018." << '\n';
    std::cout << u"This is a bigger Unicode Character: \u2018." << '\n';
    std::cout << U"This is a Unicode Character: \U00002018." << '\n';

    auto moved_v = move_vector();
    std::cout << "vector's address: " << &moved_v << '\n';
    std::cout << "vector's first element address: " << &moved_v[0] << '\n';
    return 0;
}
