#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

void genPyrN(int rows) {
  if (rows < 0) return;
  // save the last row here
  std::vector<int> last(1, 1);
  std::cout << last[0] << std::endl;
 
  for (int i = 1; i <= rows; i++) {
    // work on the next row
    std::vector<int> thisRow;
    thisRow.reserve(i+1);
    thisRow.push_back(last.front()); // beginning of row
    std::transform(last.begin(), last.end()-1, last.begin()+1, std::back_inserter(thisRow), std::plus<int>()); // middle of row
    thisRow.push_back(last.back()); // end of row
 
    for (int j = 0; j <= i; j++)
      std::cout << thisRow[j] << " ";
    std::cout << std::endl;
 
    last.swap(thisRow);
  }
}

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <level_number>\n";
        return -1;
    }

    std::size_t max_level;
    std::stringstream(argv[1]) >> max_level;

    if (max_level <= 0) {
        std::cout << "Incorrect parameter.\n";
        return -1;
    }

    genPyrN(max_level);

    std::vector<int> last(1, 1);
    std::cout << last[0] << '\n';

    for (std::size_t i = 1; i <= max_level; i++) {
        std::vector<int> this_row;
        this_row.reserve(i + 1);
        this_row.push_back(last.front());
        std::transform(last.begin(), last.end() - 1, last.begin() + 1, std::back_inserter(this_row), std::plus<int>());
        this_row.push_back(last.back());

        for (std::size_t j = 0; j <= i; j++) {
            std::cout<< this_row[j] << " ";
        }
        std::cout << '\n';

        last.swap(this_row);
    }

    return 0;
}
