#include <iostream>
#include <fstream>
#include <boost/regex.hpp>
#include <streambuf>
#include <iterator>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <file_name>\n";
        return -1;
    }

    std::ifstream input(argv[1]);

    std::istreambuf_iterator<char> inputBegin(input); 
    std::istreambuf_iterator<char> inputEnd;
    std::string stringInput(inputBegin, inputEnd);
    size_t result_index = stringInput.find("status=\"error\"");
    if (result_index != std::string::npos)
    {
        std::cout << "error found" << '\n';
        std::string::iterator i(stringInput.begin()+ result_index);
        std::cout << std::string(i, std::find(i, stringInput.end(), '\n')) << '\n';
        return 1;
    }
    
    std::cout << "No error found." << '\n';

    return 0;
}
