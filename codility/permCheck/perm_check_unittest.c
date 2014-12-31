#include "perm_check.h"
#include <vector>
#include "gtest/gtest.h"

struct param_entry_t {
    param_entry_t(std::vector<int> &A, int result): 
        _A(A),
        _result(result){ 
    };
    std::vector<int> _A;
    int _result;
};

class countAbsDifferenceParameters : public ::testing::TestWithParam<param_entry_t>{
};

TEST_P( countAbsDifferenceParameters, multipleNegativeValues){
    // Test params
    std::vector<int> A = GetParam()._A;

    long int is_permutation = solution(A);

    EXPECT_EQ(GetParam()._result, is_permutation);
}

std::vector<int> v1 = {1};
std::vector<int> v2 = {1, 2, 3, 4, 5};
std::vector<int> v3 = {1, 2, 4, 5};
std::vector<int> v4 (100000, 1000000000);
std::vector<int> v5 = {4, 1, 3, 2};
std::vector<int> v6 = {4, 1, 3};
std::vector<int> v7 = {1, 2, 2, 5, 5};


param_entry_t p1(v1, 1);
param_entry_t p2(v2, 1);
param_entry_t p3(v3, 0);
param_entry_t p4(v4, 0);
param_entry_t p5(v5, 1);
param_entry_t p6(v6, 0);
param_entry_t p7(v7, 0);

INSTANTIATE_TEST_CASE_P( InstantionName,
                         countAbsDifferenceParameters,
                         ::testing::Values(p1, p2, p3, p4, p5, p6, p7));

/* Tests factorial of negative numbers. */
TEST(checkForPermutation, largePermutation) {
    std::vector<int> v (100000, 1);
    unsigned long sum = 0;
    for (int i = 0; i < 100000; i++) {
        v[i] = i + 1;
        sum += i + 1;
    }


   long int is_permutation = solution(v);

   EXPECT_EQ(5000050000, sum);
   EXPECT_EQ(1, is_permutation );
}
//
////// Tests factorial of 0.
////TEST(FactorialTest, Zero) {
////  EXPECT_EQ(1, Factorial(0));
////}
////
//// Tests factorial of positive numbers.
//TEST(countAbsDifference, allValuesPositive) {
//    // Numbers to be tested. /* ToDo: need to change this to test case (skramer, Fri 07 Mar 2014 09:05:32 PM CET) */
//    int A[] = {1, 2, 3, 4};
//
//    // Number of values to be tested
//    int N = 4;
//
//    // Splitting pointer
//    int division_ptr = 0;
//
//    long int min_diff = count_abs_difference(A, N, division_ptr);
//
//    EXPECT_EQ(2, min_diff);
//    EXPECT_EQ(2, division_ptr);
//}
//
//
//// Tests IsPrime()
//
//// Tests negative input.
//TEST(IsPrimeTest, Negative) {
//  // This test belongs to the IsPrimeTest test case.
//
//  EXPECT_FALSE(IsPrime(-1));
//  EXPECT_FALSE(IsPrime(-2));
//  EXPECT_FALSE(IsPrime(INT_MIN));
//}
//
//// Tests some trivial cases.
//TEST(IsPrimeTest, Trivial) {
//  EXPECT_FALSE(IsPrime(0));
//  EXPECT_FALSE(IsPrime(1));
//  EXPECT_TRUE(IsPrime(2));
//  EXPECT_TRUE(IsPrime(3));
//}
//
//// Tests positive input.
//TEST(IsPrimeTest, Positive) {
//  EXPECT_FALSE(IsPrime(4));
//  EXPECT_TRUE(IsPrime(5));
//  EXPECT_FALSE(IsPrime(6));
//  EXPECT_TRUE(IsPrime(23));
//}
//
//// Step 3. Call RUN_ALL_TESTS() in main().
////
//// We do this by linking in src/gtest_main.cc file, which consists of
//// a main() function which calls RUN_ALL_TESTS() for us.
////
//// This runs all the tests you've defined, prints the result, and
//// returns 0 if successful, or 1 otherwise.
////
//// Did you notice that we didn't register the tests?  The
//// RUN_ALL_TESTS() macro magically knows about all the tests we
//// defined.  Isn't this convenient?
