#include <iostream>

#define foo(lineNumber) foo_(__LINE__)
#define bar(filename) bar_(filename, __LINE__, __FILE__)
#define fooBar(foo) fooBar_(foo, __LINE__, __FILE__)

void foo_(int lineNumber)
{
    std::cout << "Line number passed was: " << lineNumber << '\n';
}


void bar_(std::string filename, int line, std::string sourceFile)
{
    std::cout << filename << " moved in line " << sourceFile << ":" << line << '\n';
}

class Foo
{
    public:
        std::string f = "Foo::f member";
};

void fooBar_(Foo f, int line, std::string file)
{
    std::cout << "Foo version " << f.f << " called in line: " << file << ":" << line << '\n';
}


int main()
{
    foo();
    foo();

    bar("someFileName");
    // This won't compile - typesafe?
    // bar(5);

    fooBar(Foo());
    // This won't compile either
    // fooBar("someTestString");
    return 0;
}
