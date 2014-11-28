#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

class SequenceGenerator
{
public:
    explicit SequenceGenerator (int start=0) : number(start) {}
    int operator()() { return number++; }
private:
    int number;
};

int main()
{
    const int N = 10;
    std::vector<int> v1(N), v2(N);
    SequenceGenerator gen;
    std::generate(v1.begin(), v1.end(), gen);
    std::generate(v2.begin(), v2.end(), gen);

    std::cout << "V1: ";
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\nV2: ";
    std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout << "\nInner product: " << std::inner_product(v1.begin(), v1.end(), v2.begin(), 0) << '\n';
    std::cout << "\nAfter transformation: \n";
    std::transform(v1.begin(), v1.end(), v2.begin(), v1.begin(), std::multiplies<int>());
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "Inner product using transform: " << std::accumulate(v1.begin(), v1.end(), static_cast<int>(0)) << '\n';
    std::cout << "\n";


    return 0;
}
