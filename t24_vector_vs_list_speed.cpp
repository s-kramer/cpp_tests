#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <sstream>
#include <time.h>
#include <stdlib.h>
using namespace std::chrono;

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <element_number>\n";
        return -1;
    }

    std::istringstream ss(argv[1]);
    int count = 0;
    if (!(ss >> count)) {
        std::cout << "Invalid number " << argv[1] << '\n';
        return -1;
    }

    srand(time(NULL));
    std::vector<int> v (count, 0);
    std::vector<int>::iterator vit = v.begin();
    for (auto i = v.begin(); i != v.end(); i++) {
        *i = rand() % count;
    }

    high_resolution_clock::time_point t1, t2; 

    t1 = high_resolution_clock::now();
    for (int i = 0; i < count; i++) {
        v.erase(vit + rand() % (count - i));
    }
    t2 = high_resolution_clock::now(); 

    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "Vector moving took me " << time_span.count() << " seconds." << '\n';

    std::list<int> l (count, 0);
    std::list<int>::iterator lit;
    for (auto i = l.begin(); i != l.end(); i++) {
        *i = rand() % count;
    }

    t1 = high_resolution_clock::now(); 
    for (int i = 0; i < count; i++) {
        lit = l.begin();
        int end = rand() % (count - i);
        for (int j = 0; j < end; j++) {
            lit++;
        }

        l.erase(lit);
    }
    t2 = high_resolution_clock::now(); 

    time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "List moving took me   " << time_span.count() << " seconds." << '\n';

    return 0;
}
