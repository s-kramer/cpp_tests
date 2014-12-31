#include "smallest_diff.h"
#include "gtest/gtest.h"

struct param_entry_t {
    param_entry_t(int *A, int N, int division_ptr, long int result): 
        _A(A),
        _N(N),
        _division_ptr(division_ptr),
        _result(result){ 
    };
    int *_A;
    int _N;
    int _division_ptr;  //0-based
    long int _result;
};

class countAbsDifferenceParameters : public ::testing::TestWithParam<param_entry_t>{
};

TEST_P( countAbsDifferenceParameters, multipleNegativeValues){
    // Test params
    int *A = GetParam()._A;
    int  N = GetParam()._N;

    // Points to where the division happened
    int division_ptr = -1;

    long int min_diff = count_abs_difference(A, N, division_ptr);

    EXPECT_EQ(GetParam()._result, min_diff);
    EXPECT_EQ(GetParam()._division_ptr, division_ptr);
}

int A0[] = {1, 2, 3, 4, 5};
int A[]  = {-1, -2, -3, -4, -5};
int B[]  = {-158, -111, -100, -115, -130};
int C[]  = {-958, -985, -971, -975, -981};
int D[]  = {1000, 1000};
int E[]  = {-1000, 1000};
int F[]  = {1000, -1000};
param_entry_t p1(   A0 /* values */,
                    5  /* values count */,
                    2  /* pointer */,
                    3  /* result */);
param_entry_t p2(A, 5, 2, 3);
param_entry_t p3(B, 5, 1, 76);
param_entry_t p4(C, 5, 2, 958);
param_entry_t p5(D, 2, 0, 0);
param_entry_t p6(E, 2, 0, 2000);
param_entry_t p7(F, 2, 0, 2000);

INSTANTIATE_TEST_CASE_P( InstantionName,
                         countAbsDifferenceParameters,
                         ::testing::Values(p1, p2, p3, p4, p5, p6, p7));

//// Tests factorial of negative numbers.
//TEST(countAbsDifference, allValuesNegative) {
//    int A[] = {-1, -2, -3, -4};
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
