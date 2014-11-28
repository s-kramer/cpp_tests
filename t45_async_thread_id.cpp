#include <mutex>
#include <future>
#include <thread>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
mutex iomutex;

double foo(int i)
{
    this_thread::sleep_for(chrono::seconds(2));
    lock_guard<mutex> lg(iomutex);
    cout << "\nthread index=> " << i << ", id=> "<< this_thread::get_id();
    return sqrt(i);
}

int main()
{
    cout << "\nmain thread id=>" << this_thread::get_id();
    vector<future<double>> futureVec;

    for (int i = 0; i < 10; ++i)
        futureVec.push_back(async(launch::async, foo, i));
        // futureVec.push_back(async(foo, i));

    for (auto& fut : futureVec)
    {
        auto x = fut.get();
        lock_guard<mutex> lg(iomutex);
        cout << endl << x;
    }

    cout << "\ndone\n";
}
