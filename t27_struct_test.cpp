#include <iostream>

struct Widget {
    public:
        Widget(int v) : a(v) {std::cout << "Widget constructor\n";};
        void identify(void) {std::cout << "Widget a member: " << a << '\n';};

    private:
        int a; 
};

struct D_widget : public Widget {
    public:
        D_widget(int v) : Widget(v), b(v) {std::cout << "D_widget constructor\n";};
        void d_identify(void) {std::cout << "D_widget b: " << b << '\n'; identify();};
    private:
        int b;
};

int main()
{
    Widget w(42);
    w.identify();
    D_widget d(45);
    d.d_identify();
    return 0;
}
