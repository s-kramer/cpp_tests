#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <input_file> <output_file>\n";
        return -1;
    }
    std::ifstream input(argv[1]);
    std::ofstream output(argv[2]);
    output << input.rdbuf();

    return 0;
}
