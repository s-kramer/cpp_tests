#include <iostream>
#include <boost/scoped_ptr.hpp>
#include <fcntl.h>
#include <cstdio>
#include <vector>

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
    int values_array[] = {5, 16, 55, 123, 222};
    std::vector<unsigned int> p (values_array, values_array + sizeof (values_array) / sizeof (int));
    
    
    ssize_t ret = 0;
    int f = open_file();

    ret = write (f, &p, p.size() * sizeof (unsigned int));

    if (ret < 0)
    {
        perror ("Write error.");
        return ret;
    }
    else
        std::cout << "Write status: " << ret << '\n';
    close(f);

    f = open_file();
    for (int i =0; i < 2; i++)
    {
        ret = read (f, &p, sizeof (unsigned int));
        
        if (ret < 0)
        {
            perror ("Read error.");
            return ret;
        }
        else
            std::cout << "Read status: " << ret << '\n';
    }
    for (auto i : p)
        std::cout << *i << " " << &(*i) << " " << i << '\n';

    close(f);

    return 0;
}
