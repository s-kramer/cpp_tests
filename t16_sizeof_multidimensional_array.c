#include <iostream>

void print_array(int array[3][3]);
void print_any_array(int array[], size_t elements);
void print_2D_array(int array[][3], size_t elements);

int main(void) {
    int array[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    print_array(array);
    print_2D_array(array, sizeof(array) / sizeof(*array));

    return 0;
}

void print_array(int array[3][3]) {
    for(int x = 0; x < 3; x ++) {
        for(int y = 0; y < 3; y ++) {
            std::cout << array[x][y] << ' ';
        }
        std::cout << std::endl;
    }
}

void print_any_array(int array[], size_t elements) {
    for(size_t i = 0; i < elements; i ++) {
        std::cout << array[i] << ' ';
    }
}

void print_2D_array(int array[][3], size_t elements) {
    for(size_t i = 0; i < elements; i ++) {
        print_any_array(array[i], 3);
        std::cout << std::endl;
    }
}
