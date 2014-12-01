#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "perm_missing.h"

#define MAX_STRING_SIZE 2

int main(int argc, char const *argv[])
{
    if (argc == 1) {
        printf("Usage: %s <permutations>\n", argv[0]);
        return -1;
    }

    int i = 0;

    char **arg_table = (char**) malloc( (argc -1) * sizeof(char*)); 
    if (!arg_table) {
        perror("Malloc failed");
        return -errno;
    }

    for (i = 1; i < argc; i++) {
        //arg_table[i - 1] = argv[i];
        arg_table[i - 1] = (char*) malloc(MAX_STRING_SIZE * sizeof(char)); 
        if (!arg_table[i - 1]) {
            perror("Malloc failed");
            return -errno;
        }
        strcpy(arg_table[i - 1], argv[i]);
    }

    printf("Permutations: \n");
    for (i = 0; i < argc - 1; i++) {
        printf("arg_table[%i] = %s\n", i, arg_table[i]);
    }

    char* result = find_missing_permutation(arg_table, argc - 1, MAX_STRING_SIZE);
    printf("Missing permutation: %s\n", result);

    for (i = 0; i < argc - 1; i++) {
        free(arg_table[i]);
        arg_table[i] = NULL;
    }
    free(arg_table);
    return 0;
}
