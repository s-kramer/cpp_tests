#include <iostream>
#include <vector>
#include <list>

/* Note: Always prefer vector to list, unless you have other pointers you need to keep valid at the time of insertion\removal.
 * (skramer, Mon 24 Mar 2014 09:19:39 AM CET) 
 */
int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    auto it= v.begin() + 2;
    std::cout << "Vector iterator before deletion: " << *it << '\n';
    v.erase(v.begin() + 1);
    std::cout << "Vector iterator after deletion: " << *it << '\n';

    std::list<int> mylist = {1, 2, 3, 4, 5, 6};
    std::list<int>::iterator lit1, lit2;
    lit1 = lit2 = mylist.begin();
    advance(lit1, 1);
    advance(lit2, 2);
    std::cout << "List iterator 1 before deletion: " << *lit1 << '\n';
    std::cout << "List iterator 2 before deletion: " << *lit2 << '\n';
    mylist.erase(lit1);
    std::cout << "List iterator 1 after deletion: " << *lit1 << '\n';
    std::cout << "List iterator 2 after deletion: " << *lit2 << '\n';



    return 0;
}

