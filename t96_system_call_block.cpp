#include <iostream>
#include <cstdlib>

int main()
{
    // This one doesn't block
    std::cout <<  "Before xdg-open call" << '\n'; 
    system("xdg-open /home/skramer/Desktop/test.txt");
    std::cout <<  "After xdg-open call" << '\n'; 

    // This one doesn't have any effect - the system tries to execute this
    std::cout <<  "Before plain filename call" << '\n'; 
    system("/home/skramer/Desktop/another_text.txt");
    std::cout <<  "After plain filename call" << '\n'; 

    // This one blocks until leafpad is closed
    std::cout <<  "Before leafpad call" << '\n'; 
    system("leafpad /home/skramer/Desktop/test.txt");
    std::cout <<  "After leafpad call" << '\n'; 
    return 0;
}
