#include <iostream>
#include <map>

int main()
{
    std::map<int, int> map;
    map.insert(std::make_pair<int, bool>(5, true));
    map.insert(std::make_pair<int, bool>(6, true));
    map.insert(std::make_pair<int, bool>(7, true));
    map.insert(std::make_pair<int, bool>(7, true));

    return 0;
}
