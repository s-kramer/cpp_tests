#include <iostream>
#include <unordered_map>
#include <memory>
#include <string>

class Base
{
public:
    explicit Base (void) = default;
    virtual ~Base () = default;
    
    Base (const Base&) = delete;
    Base (const Base&&) = delete;
    Base operator=(const Base&) = delete;
    Base operator=(const Base&&) = delete;
};

template <typename T>
T* getHashedT(const std::string& key, std::unordered_map<std::string, std::unique_ptr<T>>& map)
{
    std::unique_ptr<T>& entry = map[key];
    if (entry)
    {
        return entry.get();
    }

    entry = std::make_unique<T>();
    return entry.get();
}

template <typename T>
T* getHashetTInsertVersion(const std::string& key, std::unordered_map<std::string, std::unique_ptr<T>>& m)
{
    // This creates a pair (passed a string and creates unique_ptr and Base object at every lookup)
    auto r = m.insert(std::make_pair<std::string, std::unique_ptr<T>>(key, nullptr));
    if (r.first) 
    {
        r.second = std::make_unique<T>();
    }
    return r.second.get();
}

int main()
{
    std::unordered_map<std::string, std::unique_ptr<Base>> m;
    auto b = getHashedT("first", m);

    return 0;
}
