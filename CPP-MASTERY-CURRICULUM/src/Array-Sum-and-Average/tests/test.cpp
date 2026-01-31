#include "solution.h"
#include <gtest/gtest.h>
#include <memory>

struct SolutionTest : public ::testing::Test {
    std::unique_ptr<Solution> solution;

    void SetUp() override { solution = std::make_unique<Solution>(); }
    void TearDown() override {}
};

// --- Sum Tests ---
TEST_F(SolutionTest, SumWithPositiveNumbers) {
    int arr[] = {1, 2, 3, 4, 5};
    ASSERT_EQ(solution->sum(arr, 5), 15);
}

TEST_F(SolutionTest, SumWithNegativeNumbers) {
    int arr[] = {-1, -2, -3, -4, -5};
    ASSERT_EQ(solution->sum(arr, 5), -15);
}

TEST_F(SolutionTest, SumWithMixedNumbers) {
    int arr[] = {-10, 20, -5, 15, -3};
    ASSERT_EQ(solution->sum(arr, 5), 17);
}

TEST_F(SolutionTest, SumWithSingleElement) {
    int arr[] = {42};
    ASSERT_EQ(solution->sum(arr, 1), 42);
}

TEST_F(SolutionTest, SumWithZeros) {
    int arr[] = {0, 0, 0, 0};
    ASSERT_EQ(solution->sum(arr, 4), 0);
}

TEST_F(SolutionTest, SumWithMixedIncludingZero) {
    int arr[] = {5, 0, -5, 10, 0};
    ASSERT_EQ(solution->sum(arr, 5), 10);
}

TEST_F(SolutionTest, SumWithLargeArray) {
    int arr[100];
    for (int i = 0; i < 100; ++i) {
        arr[i] = i + 1;
    }
    ASSERT_EQ(solution->sum(arr, 100), 5050); // Sum of 1 to 100
}

TEST_F(SolutionTest, SumWithLargeNumbers) {
    int arr[] = {1000000, 2000000, 3000000};
    ASSERT_EQ(solution->sum(arr, 3), 6000000);
}

// --- Average Tests ---
TEST_F(SolutionTest, AverageWithPositiveNumbers) {
    int arr[] = {2, 4, 6, 8, 10};
    ASSERT_DOUBLE_EQ(solution->average(arr, 5), 6.0);
}

TEST_F(SolutionTest, AverageWithNegativeNumbers) {
    int arr[] = {-2, -4, -6, -8, -10};
    ASSERT_DOUBLE_EQ(solution->average(arr, 5), -6.0);
}

TEST_F(SolutionTest, AverageWithMixedNumbers) {
    int arr[] = {-10, 10, -5, 5};
    ASSERT_DOUBLE_EQ(solution->average(arr, 4), 0.0);
}

TEST_F(SolutionTest, AverageWithSingleElement) {
    int arr[] = {42};
    ASSERT_DOUBLE_EQ(solution->average(arr, 1), 42.0);
}

TEST_F(SolutionTest, AverageResultingInFraction) {
    int arr[] = {1, 2, 3};
    ASSERT_DOUBLE_EQ(solution->average(arr, 3), 2.0); // 6/3 = 2.0
}

TEST_F(SolutionTest, AverageWithOddSum) {
    int arr[] = {1, 2, 3, 4, 5};
    ASSERT_DOUBLE_EQ(solution->average(arr, 5), 3.0); // 15/5 = 3.0
}

TEST_F(SolutionTest, AverageWithDecimalResult) {
    int arr[] = {1, 2, 3, 4};
    ASSERT_DOUBLE_EQ(solution->average(arr, 4), 2.5); // 10/4 = 2.5
}

TEST_F(SolutionTest, AverageWithNonDivisibleSum) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    ASSERT_DOUBLE_EQ(solution->average(arr, 7), 4.0); // 28/7 = 4.0
}

TEST_F(SolutionTest, AverageWithTwoElements) {
    int arr[] = {5, 10};
    ASSERT_DOUBLE_EQ(solution->average(arr, 2), 7.5);
}

TEST_F(SolutionTest, AverageWithZeros) {
    int arr[] = {0, 0, 0};
    ASSERT_DOUBLE_EQ(solution->average(arr, 3), 0.0);
}

TEST_F(SolutionTest, AverageWithLargeNumbers) {
    int arr[] = {1000000, 2000000, 3000000};
    ASSERT_DOUBLE_EQ(solution->average(arr, 3), 2000000.0);
}

TEST_F(SolutionTest, AverageRequiringPrecision) {
    int arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    ASSERT_DOUBLE_EQ(solution->average(arr, 10), 1.0);
}
