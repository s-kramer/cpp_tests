#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

/*
 * class List_entry
 * {
 * public:
 *     explicit List_entry() 
 *     { 
 *         increment_length(); 
 *     };
 * 
 *     explicit List_entry (int value, List_entry *next) 
 *         : _value(value)
 *         , _next(next)
 *     { 
 *         increment_length();
 *     };
 *      
 *     virtual ~List_entry () {};
 * 
 *     int get_value (void) { return _value; };
 *     List_entry* get_next (void) { return _next; };
 * 
 *     int get_list_length(void) { return List_entry::length; };
 * 
 * private:
 *     int _value = 0;
 *     List_entry *_next = nullptr;
 * 
 *     void increment_length (void) { List_entry::length++; };
 *     static int length;
 * };
 */

bool jw_search ( int *list, int size, int key, int * result)
{
    // Ordered sequential search
    bool found = false;
    int i = 0;

    list[size] = key;

    for (i = 0; list[i] < key; i++)
        ;
    if ( key == list[i] && i < size ) {
        found = true;
        result = &i;
    }

    std::cout << "Key: " << key << ", i: " << i << ", result: ";
    if (result)
        std::cout << *result << '\n';
    else
        std::cout << "not found\n";
    return found;
}

bool binary_search ( int *list, int size, int key, int * result)
{
    bool found = false; 
    int low = 0, high = size - 1;
    int middle = 0;

    while (low <= high) {
        middle = (high - low) / 2 + low;
        if (key < list[middle])
            high = middle - 1;
        else
        if (key > list[middle])
            low = middle + 1;
        else {
            found = true;
            result = &list[middle];
            break;
        }
    }

    std::cout << "Key: " << key << ", low: " << low << ", high: " << high << ", middle: " << middle << ", result: ";
    if (result)
        std::cout << *result << '\n';
    else
        std::cout << "not found\n";
    return found;
}

bool interpolation_search ( int *list, int size, int key, int * result)
{
    bool found = false;
    int low = 0, high = size - 1;
    int middle = 0;

    while (list[high] >= key && key > list[low]) {
        double low_diff = (double)key - list[low];
        double range_diff = (double)list[high] - list[low];
        double index_diff = (double)high - low;

        middle = (int)(low_diff / range_diff * index_diff + low);
        if (key > list[middle]) {
            low = middle + 1;
        }
        else if (key < list[middle]) {
            high = middle - 1;
        }
        /* This doesn't work if changing the low\high value causes the list[new_value] to point to correct value. Original (Allain) solution is better.*/
        else {
            found = true;
            result = &list[middle];
            break;
        }
    }
    std::cout << "Key: " << key << ", low: " << low << ", high: " << high << ", middle: " << middle << ", result: ";
    if (result)
        std::cout << *result << '\n';
    else
        std::cout << "not found\n";
    return found;
}

bool interpolation_search_allain ( int *list, int size, int key, int* rec )
{
  // Interpolation search
  bool found = false;
  int low = 0, high = size - 1;
  int range = 0;

  while ( list[high] >= key && key > list[low] ) {
    double low_diff = (double)key - list[low];
    double range_diff = (double)list[high] - list[low];
    double count_diff = (double)high - low;
    range = (int)( low_diff / range_diff * count_diff + low );
    if ( key > list[range] )
      low = range + 1;
    else if ( key < list[range] )
      high = range - 1;
    else
      low = range;
  }
  if ( key == list[low] ) {
    found = true;
    rec = &list[low];
  }

    std::cout << "Key: " << key << ", low: " << low << ", high: " << high << ", middle: " << range << ", result: ";
    if (rec)
        std::cout << *rec << '\n';
    else
        std::cout << "not found\n";
  return found;
}

int compar (const void *a, const void *b)
{
    if (*(int*)a > *(int*)b) return 1;
    if (*(int*)a == *(int*)b) return 0;
    else return -1;
}
int main(int argc, char const *argv[])
{

    srand(time(NULL));
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <samples_count\n";
        return -1;
    }

    const unsigned ARRAY_SIZE = std::stoi(argv[1], nullptr, 10);
    int *values = new int[ARRAY_SIZE + 1];
    int *result = nullptr;

    for (unsigned int i = 0; i < ARRAY_SIZE; i++) {
        values[i] = rand() % ARRAY_SIZE;
    }

    qsort( values, ARRAY_SIZE, sizeof(int), compar);

    for (unsigned i = 0; i < ARRAY_SIZE; i++) {
        std::cout << i << ": " << values[i] << '\n';
    }

    std::cout << "Quick search : Element was" << ((jw_search(values, ARRAY_SIZE, 6, result)) ? ("") : (" not")) << " found.\n";
    std::cout << "Binary search: Element was" << ((binary_search(values, ARRAY_SIZE, 6, result)) ? ("") : (" not")) << " found.\n";
    std::cout << "Interpolation search: Element was" << ((interpolation_search(values, ARRAY_SIZE, 6, result)) ? ("") : (" not")) << " found.\n";
    std::cout << "ALLAIN Interpolation search: Element was" << ((interpolation_search_allain(values, ARRAY_SIZE, 6, result)) ? ("") : (" not")) << " found.\n";
    delete[] values;


    // List_entry *l1 = new List_entry(), *l2 = new List_entry(1, l1), *l3 = new List_entry (2, l2), *l4 = new List_entry (3,l3);
    //List_entry l1, l2(1, &l1), l3(2, &l2), l4(3, &l3);
    ////std::list<int> list = {0, 1, 2, 3};
    //jw_search(list, 2, &result);

    //std::cout << "Result is: " << *result <<'\n';
    //delete result;
    return 0;
}

// printf "Key : %i\nlow: %i\nhigh: %i\nmiddle: %i\n", key, low, high, middle
