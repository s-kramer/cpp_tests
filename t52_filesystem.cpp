#include <iostream>
#include <boost/filesystem.hpp>
#include <iterator>
#include <algorithm>
#include <string>

namespace fs = boost::filesystem;

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        std::cout << "Usage " << argv[0] << " <filepath>" << '\n';
        return 1;
    }
    

    fs::path path = argv[1];

    try { 
        if (!fs::exists(path)) {
            std::cout << path << " doesn't exist\n";
        }
        else if (fs::is_regular_file(path)) {
            std::cout << path << " size: " << fs::file_size(path) << "B\n";
        }
        else if (fs::is_directory(path)) {
            std::vector<fs::path> paths ((fs::directory_iterator(path)), (fs::directory_iterator()));
            std::transform(begin(paths), end(paths), begin(paths), [](fs::path& filepath) 
            {
                return filepath.filename();
            });
            std::sort(begin(paths), end(paths));

            std::cout << path << "is a directory containing:\n";
            std::copy(begin(paths), end(paths), std::ostream_iterator<fs::path>(std::cout, "\n"));
        }
        else {
            std::cout << path << " is neither a regular file not a directory.\n";
        }

    }
    catch (fs::filesystem_error& e)
    {
        std::cout << e.what() << '\n';
    }
    return 0;
}
