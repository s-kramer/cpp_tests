#include <iostream>

const int LOWER_VAL = 5;
const int UPPER_VAL = 9;

bool is_in_range(int val, int lower = LOWER_VAL, int upper = UPPER_VAL)
{
    return (val >= lower && val <=upper);
}

int main()
{
    long int sum = 0;
    double average = 0;
    unsigned count = 0;
    int num = 0;
    while (1) {
        std::cout << "Enter number from the range 5 - 9 inclusive:\n";
        std::cin >> num;
        if (!is_in_range(num)) {
            std::cout << "The number " << num << " is not within the range <" << LOWER_VAL << ", " << UPPER_VAL << ">.\n";
            continue;
        }
        sum += num;
        count++;
        average = static_cast<double>(sum) / count;
        std::cout << "Current average: " << average << '\n';
    }
    return 0;
}
