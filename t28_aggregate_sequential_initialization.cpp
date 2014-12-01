#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

struct Widget {
    public:
        Widget(int num = Widget::count++) :
            value(num)
        {
            // std::cout << "Widget default constructor\n";
            // std::cout << "Count: " << count << '\n';
        }

        Widget(const Widget &rhs)
        {
            // std::cout << "Widget copy constructor\n";
            // std::cout << "Count: " << count << '\n';
            value = rhs.value;
            count++;
        }
        unsigned value;

        ~Widget(void)
        {
            count--;
            // std::cout << "Count: " << count-- << '\n';
        }

        unsigned get_object_count(void) const {return count;};
    private:
        static unsigned count;
};

void print_widget(const Widget &w)
{
    std::cout << w.get_object_count() << '\n';
}

unsigned Widget::count = 0;

template<typename T, std::size_t N>
std::size_t arr_size(T(&)[N])
{
    return N;
}

int main()
{
    std::vector<Widget> arr(10, Widget());
    std::for_each(arr.begin(), arr.end(), print_widget);

    Widget widget_array[10] = {};
    for (std::size_t i = 0; i < arr_size(widget_array); i++) {
        print_widget(i);
    }

    for(auto i : widget_array)
        print_widget(i);

    return 0;
}
