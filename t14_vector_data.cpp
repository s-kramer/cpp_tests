#include <iostream>
#include <cstdlib>
#include <boost/scoped_ptr.hpp>
#include <fcntl.h>
#include <cstdio>
#include <vector>
#include <time.h>

int open_file (const char* path = "scoped_ptr_test")
{
    int f = open (path, O_RDWR | O_NONBLOCK);
    if (f < 0)
    {
        perror ("File opening went bad.\n");
    }
    return f;
}

int main()
{
    //boost::scoped_ptr<unsigned int> p ( new unsigned int (5));
    
    //
    //alternative vector test
    //

    //int values_array[] = {5, 16, 55, 123, 222};
    //std::vector<unsigned int> p (values_array, values_array + sizeof (values_array) / sizeof (int));
    
    std::vector <unsigned int> p (10);
    unsigned int* p_data = p.data();

    auto iterator = p.begin();

    for (auto& i : p)
        i = rand() % 1000;

    ssize_t ret = 0;
    int f = open_file();

    ret = write (f, &(*iterator), p.size() * sizeof (unsigned int));
    p_data += ret / sizeof (unsigned int);  //moves the pointer to unwritten data

    if (ret < 0)
    {
        perror ("Write error.");
        return ret;
    }
    else
        std::cout << "Write status: " << ret << '\n';
    close(f);

    f = open_file();
    ret = read (f, p.data(), p.size() * sizeof (unsigned int));

    if (ret < 0)
    {
        perror ("Read error.");
        return ret;
    }
    else
        std::cout << "Read status: " << ret << '\n';

    for (auto& i : p)
        std::cout << i << " " << &i << '\n';

    for (auto i = p.begin(); i != p.end(); ++i)
        std::cout << &(*i) << " " << *i << '\n';

    close(f);

    return 0;
}

