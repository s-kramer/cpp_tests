#include "perm_missing.h"

char* find_missing_permutation(char** A, int N /* number of strings */, int width /* width of a single string */)
{
    /* Get the number of elements passed */
    int nElements = N;

    /* The same char should occur in each column width-1 times.
     * Here we count the actual sum of characters in each column 
     * of all the strings.*/
    int *character_sums = (int*) calloc(width, sizeof(int)); 
    for (int i = 0; i < nElements; i++) {
        for (int j = 0; j < width; j++) {
            character_sums[j] += A[i][j];
        }
    }
    
    /* Count how many times each character should occur 
     * in each column of the string.*/
    int char_occurence = 1;
    for (int i = 1; i <= width - 1; i++) {
        char_occurence *= i;
    }

    /* Here we count the expected sum of characters 
     * in each column in all the strings. */
    int expected_column_sum = 0;
    for (int i = 0; i < width; i++) {
        expected_column_sum += char_occurence * (A[0][i]);
    }

    char* result = (char*) calloc(width, sizeof(char)); 
    for (int i = 0; i < width; i++) {
        result[i] = expected_column_sum - character_sums[i];
    }

    free(character_sums);

    return result;
}

