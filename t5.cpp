//check if the value assigned to the variable is returned from the assignment

#include <iostream>

int main(int argc, char const *argv[])
{
    int i = 0;

    if ( (i=5) > 0)
    {
        std::cout << i << "> 5\n";
    }
    else
        std::cout << i << '\n';
    return 0;
}
