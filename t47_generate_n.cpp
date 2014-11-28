#include <iostream>
#include <algorithm>
#include <vector>

class GenerateNumbers
{
public:
    explicit GenerateNumbers () {};
    unsigned operator()() { return currentNumber++; };
private:
    unsigned currentNumber = 0;
};

int main()
{
    std::vector<int> numbers;
    /* This creates 20 objects. resize() is necessary is passing begin(numbers) 
     * to gerenate_n, as the algorithm doesn't modify the vector (it doesn't 
     * resize it, not change the end iterator). 
     * Alternatively, use std::back_inserter(numbers) */
    // numbers.resize(20);
    numbers.resize(20);

    std::generate_n(begin(numbers), 20, GenerateNumbers());

    for(auto number : numbers) std::cout << number << '\n';

    return 0;
}
