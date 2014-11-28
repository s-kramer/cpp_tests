#include <iostream>
#include <memory>

class SingleCharPrinter
{
public:
    explicit SingleCharPrinter (void) = default;
    virtual void draw(void) = 0;
};

class ACharPrinter : public SingleCharPrinter
{
public:
    explicit ACharPrinter (void) = default;

    virtual void draw(void) override
    {
        std::cout << "A";
    }
};

class CharPrinterDecorator : public SingleCharPrinter
{
public:
    explicit CharPrinterDecorator (SingleCharPrinter *toBeDecorated) : toBeDecorated_(toBeDecorated) {};
    virtual void draw(void) override
    {
        toBeDecorated_->draw();
    }
private:
    std::unique_ptr<SingleCharPrinter> toBeDecorated_;
};

class BCharPrinter : public CharPrinterDecorator
{
public:
    explicit BCharPrinter (SingleCharPrinter *toBeDecorated) : CharPrinterDecorator(toBeDecorated) {};
    virtual void draw(void) override
    {
        CharPrinterDecorator::draw();
        std::cout << "B";
    }
};

class CCharPrinter : public CharPrinterDecorator
{
public:
    explicit CCharPrinter (SingleCharPrinter *toBeDecorated) : CharPrinterDecorator(toBeDecorated) {};
    virtual void draw(void) override
    {
        CharPrinterDecorator::draw();
        std::cout << "C";
    }
};

class DCharPrinter : public CharPrinterDecorator
{
public:
    explicit DCharPrinter (SingleCharPrinter *toBeDecorated) : CharPrinterDecorator(toBeDecorated) {};
    virtual void draw(void) override
    {
        CharPrinterDecorator::draw();
        std::cout << "D";
    }
};

int main()
{
    typedef std::unique_ptr<SingleCharPrinter> charptr;
    charptr A(new ACharPrinter);
    charptr AB(new BCharPrinter(new ACharPrinter));
    charptr ABCD(new DCharPrinter(new CCharPrinter(new BCharPrinter(new ACharPrinter))));

    A->draw();
    std::cout << '\n';
    AB->draw();
    std::cout << '\n';
    ABCD->draw();
    std::cout << '\n';
    return 0;
}
