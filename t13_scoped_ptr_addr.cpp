#include <iostream>
#include <boost/scoped_ptr.hpp>
#include <fcntl.h>
#include <cstdio>
#include <cstdlib>
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
    srand (time ( NULL));

    boost::scoped_ptr<unsigned int> p (new unsigned int (rand() % 100));
    
    ssize_t ret = 0;
    int f = open_file();

    ret = write (f, p.get(), sizeof (unsigned int));

    if (ret < 0)
    {
        perror ("Write error.");
        return ret;
    }
    else
        std::cout << "Write status: " << ret << '\n';

    close(f);

    f = open_file();
    ret = read (f, p.get(), sizeof (unsigned int));

    if (ret < 0)
    {
        perror ("Read error.");
        return ret;
    }
    else
        std::cout << "Read status: " << ret << '\n';

    std::cout << &(*p) << " " << *p << " " << &p << " " << p << '\n';

    close(f);

    return 0;
}
