#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v(20, 0);
    v[0] = 0;
    v[1] = 1;
    
    // Modify the existing container
    // This iterates over [0, 17] and [1, 18] giving results in [2, 19]
    std::transform(v.begin(), v.begin() + v.size() -2, v.begin() + 1, v.begin() + 2, [](int i, int j) {
        return i + j;
    });

    std::cout <<  "Some vector metadata:\n";
    std::cout <<  "V size: " << v.size() << ", V capacity: " << v.capacity() << ", v[v.capacity() -1] " <<  v[v.capacity() -1 ] << "v.begin() + v.capacity() -2: " << *(v.begin() + v.capacity() -2) << '\n';    
    std::cout <<  "Modified container" << '\n'; 
    int counter = 0;
    std::for_each(v.begin(), v.end(), [&counter](int i) { std::cout <<  counter++ <<  ": "  << i << '\n'; });

    v.clear();
    v.reserve(20);
    v.push_back(0);
    v.push_back(1);
    std::cout << "V's address: " <<  v.data() << '\n';  

    // Create fibonacci's sequence on the fly
    // This iterates over 2 ranges: [0, 18 (cap -2)) == [0, 17] & [1, 18]
    std::transform(v.begin(), v.begin() + v.capacity() -2, v.begin() + 1, std::back_inserter(v), [] (int i, int j) {
        return i + j;
    });
    std::cout << "V's address: " <<  v.data() << '\n' <<  "Pushing another element causes realocation \n" ;  
    
    // This causes vector's realocation
    v.push_back(21);
    std::cout << "V's address: " <<  v.data() << '\n';  

    std::cout <<  "Pushed back container" << '\n'; 
    counter = 0;
    std::for_each(v.begin(), v.end(), [&counter](int i) { std::cout <<  counter++ <<  ": "  << i << '\n'; });




    return 0;
}
