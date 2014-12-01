#include <iostream>
#include <string.h>

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <string_to_check>\n";
        return -1;
    }

    std::size_t pal_length = strlen(argv[1]);
    for (std::size_t i = 0; i < pal_length; i++) {
        if (argv[1][i] != argv[1][pal_length - 1 - i]) {
            std::cout << "Not a palindrome\n";
            break;
        }
    }
    std::cout << "palindrome detected\n";

    
    std::string pal(argv[1]);
    for (std::size_t i = 0; i < pal.length() / 2; i++) {
        if (pal[i] != pal[pal.length() - i - 1]) {
            std::cout << pal << " is not a palindrome\n";
            break;
        }
    }
    std::cout << pal << " is a palindrome\n";

    if(std::equal(pal.begin(), pal.begin() + pal.length() / 2, pal.rbegin())) {
        std::cout << "Is a palidrome again\n";
    } else {
        std::cout << "Not a palidrome!\n";
    }


    return 0;
}
