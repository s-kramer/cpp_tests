#include "perm_missing.h"
#include "gtest/gtest.h"

struct param_entry_t {
    param_entry_t(  /* PARAMETERS */
                    char *A[],  /* array of permutations */
                    int  N,     /* number of permutations */
                    int  width, /* string width */
                    /* RESULTS */
                    char *result): 
        _A(A),
        _N(N),
        _width(width),
        _result(result)
    {
    };
    char **_A;
    int _N;
    int _width;
    char* _result;
};

class findMissingPermutation : public ::testing::TestWithParam<param_entry_t>{
};

TEST_P( findMissingPermutation, ElementPermutations){
    // Array of strings
    char **permutations     = GetParam()._A;
    // Number of strings
    int  nPermutations      = GetParam()._N;
    // Width of the strings
    int  width              = GetParam()._width;


    char* result = find_missing_permutation(permutations, 
                                             nPermutations, width);


    EXPECT_EQ(0, strcmp(GetParam()._result, result)) << "Expected: " << GetParam()._result << ", actual: " << result << '\n';
}

char* A[] = {(char*)"AB", /* (char*)"BA", */};

char* B[] = {(char*)"ABC", (char*)"ACB",
             (char*)"BAC", (char*)"BCA",
             (char*)"CAB", /* (char*)"CBA" */};

char* C[] = {(char*)"BCDA", (char*)"DCAB", (char*)"BDAC", (char*)"BCAD", 
             (char*)"CDBA", (char*)"CADB", (char*)"DABC", (char*)"CABD", 
             (char*)"BDCA", (char*)"DACB", (char*)"BADC", (char*)"BACD", 
             (char*)"CBDA", (char*)"CDAB", /*(char*)"DBAC",*/ (char*)"CBAD", 
             (char*)"DCBA", (char*)"ACDB", (char*)"ADBC", (char*)"ACBD", 
             (char*)"DBCA", (char*)"ADCB", (char*)"ABDC", (char*)"ABCD"};

param_entry_t p1(   A           /* values */,
                    1           /* number of permutations */,
                    2           /* width of the strings */,
                    (char*)"BA" /* result */);
param_entry_t p2(B, 5, 3, (char*)"CBA");
param_entry_t p3(C, 23, 4, (char*)"DBAC");


INSTANTIATE_TEST_CASE_P( InstantionName,
                         findMissingPermutation,
                         ::testing::Values(p1, p2, p3));
