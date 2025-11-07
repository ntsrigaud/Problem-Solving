#include "solution.h"
#include <gtest/gtest.h>
#include <memory>

struct SolutionTest : public ::testing::Test {
  std::unique_ptr<Solution> solution;

  void SetUp() override { solution = std::make_unique<Solution>(); }
  void TearDown() override {}
};

// --- Test cases for prime numbers (should return 0) ---
TEST_F(SolutionTest, PrimeNumberReturnsZeroSmall) {
  EXPECT_EQ(solution->prime_gap(2), 0);
  EXPECT_EQ(solution->prime_gap(3), 0);
  EXPECT_EQ(solution->prime_gap(5), 0);
  EXPECT_EQ(solution->prime_gap(7), 0);
}

TEST_F(SolutionTest, PrimeNumberReturnsZeroMedium) {
  EXPECT_EQ(solution->prime_gap(11), 0);
  EXPECT_EQ(solution->prime_gap(13), 0);
  EXPECT_EQ(solution->prime_gap(17), 0);
  EXPECT_EQ(solution->prime_gap(19), 0);
  EXPECT_EQ(solution->prime_gap(23), 0);
}

TEST_F(SolutionTest, PrimeNumberReturnsZeroLarge) {
  EXPECT_EQ(solution->prime_gap(97), 0);
  EXPECT_EQ(solution->prime_gap(101), 0);
  EXPECT_EQ(solution->prime_gap(307), 0);
  EXPECT_EQ(solution->prime_gap(541), 0);
}

// --- Test cases for numbers less than 2 (should return 0) ---
TEST_F(SolutionTest, NumbersLessThanTwoReturnZero) {
  EXPECT_EQ(solution->prime_gap(1), 0);
  EXPECT_EQ(solution->prime_gap(0), 0);
  EXPECT_EQ(solution->prime_gap(-5), 0);
}

// --- Test cases for small prime gaps ---
TEST_F(SolutionTest, SmallGapOfTwo) {
  // Gap between 3 and 5
  EXPECT_EQ(solution->prime_gap(4), 2);

  // Gap between 5 and 7
  EXPECT_EQ(solution->prime_gap(6), 2);

  // Gap between 11 and 13
  EXPECT_EQ(solution->prime_gap(12), 2);

  // Gap between 17 and 19
  EXPECT_EQ(solution->prime_gap(18), 2);
}

TEST_F(SolutionTest, SmallGapOfFour) {
  // Gap between 7 and 11
  EXPECT_EQ(solution->prime_gap(8), 4);
  EXPECT_EQ(solution->prime_gap(9), 4);
  EXPECT_EQ(solution->prime_gap(10), 4);

  // Gap between 13 and 17
  EXPECT_EQ(solution->prime_gap(14), 4);
  EXPECT_EQ(solution->prime_gap(15), 4);
  EXPECT_EQ(solution->prime_gap(16), 4);
}

TEST_F(SolutionTest, SmallGapOfSix) {
  // Gap between 23 and 29
  EXPECT_EQ(solution->prime_gap(24), 6);
  EXPECT_EQ(solution->prime_gap(25), 6);
  EXPECT_EQ(solution->prime_gap(26), 6);
  EXPECT_EQ(solution->prime_gap(27), 6);
  EXPECT_EQ(solution->prime_gap(28), 6);
}

// --- Test cases for medium prime gaps ---
TEST_F(SolutionTest, MediumGapOfEight) {
  // Gap between 89 and 97
  EXPECT_EQ(solution->prime_gap(90), 8);
  EXPECT_EQ(solution->prime_gap(91), 8);
  EXPECT_EQ(solution->prime_gap(95), 8);
  EXPECT_EQ(solution->prime_gap(96), 8);
}

TEST_F(SolutionTest, MediumGapOfTen) {
  // Gap between 139 and 149
  EXPECT_EQ(solution->prime_gap(140), 10);
  EXPECT_EQ(solution->prime_gap(145), 10);
  EXPECT_EQ(solution->prime_gap(148), 10);
}

// --- Test cases for larger prime gaps ---
TEST_F(SolutionTest, LargeGapOfFourteen) {
  // Gap between 113 and 127
  EXPECT_EQ(solution->prime_gap(114), 14);
  EXPECT_EQ(solution->prime_gap(120), 14);
  EXPECT_EQ(solution->prime_gap(126), 14);
}

TEST_F(SolutionTest, LargeGapOfTwenty) {
  // Gap between 887 and 907
  EXPECT_EQ(solution->prime_gap(888), 20);
  EXPECT_EQ(solution->prime_gap(900), 20);
  EXPECT_EQ(solution->prime_gap(906), 20);
}

// --- Test cases for consecutive numbers in the same gap ---
TEST_F(SolutionTest, ConsecutiveNumbersInSameGap) {
  // All numbers between 23 and 29 should return gap of 6
  for (int i = 24; i < 29; ++i) {
    EXPECT_EQ(solution->prime_gap(i), 6) << "Failed for k = " << i;
  }
}

TEST_F(SolutionTest, ConsecutiveNumbersInSameGapLargerRange) {
  // All numbers between 89 and 97 should return gap of 8
  for (int i = 90; i < 97; ++i) {
    EXPECT_EQ(solution->prime_gap(i), 8) << "Failed for k = " << i;
  }
}

// --- Edge case tests ---
TEST_F(SolutionTest, EdgeCaseBoundaryOfGaps) {
  // Test numbers right after a prime (start of gap)
  EXPECT_EQ(solution->prime_gap(24), 6);   // Right after 23
  EXPECT_EQ(solution->prime_gap(30), 2);   // Right after 29
  EXPECT_EQ(solution->prime_gap(114), 14); // Right after 113
}

TEST_F(SolutionTest, EdgeCaseJustBeforePrime) {
  // Test numbers right before a prime (end of gap)
  EXPECT_EQ(solution->prime_gap(28), 6);   // Right before 29
  EXPECT_EQ(solution->prime_gap(96), 8);   // Right before 97
  EXPECT_EQ(solution->prime_gap(126), 14); // Right before 127
}

// --- Test cases with larger numbers ---
TEST_F(SolutionTest, LargerNumbersHundreds) {
  EXPECT_EQ(solution->prime_gap(200), 12); // Between 199 and 211 gap is 12
  EXPECT_EQ(solution->prime_gap(300), 14); // Between 293 and 307 gap is 14
  EXPECT_EQ(solution->prime_gap(400), 4);  // Between 397 and 401 gap is 4
}

TEST_F(SolutionTest, LargerNumbersFiveHundreds) {
  EXPECT_EQ(solution->prime_gap(500), 4);  // Between 499 and 503 gap is 4
  EXPECT_EQ(solution->prime_gap(550), 10); // Between 547 and 557 gap is 10
  EXPECT_EQ(solution->prime_gap(600), 2);  // Between 599 and 601 gap is 2
}

// --- Test multiple calls with same solution object ---
TEST_F(SolutionTest, MultipleCallsCachingBehavior) {
  // First call
  int result1 = solution->prime_gap(50);
  // Second call with same value
  int result2 = solution->prime_gap(50);
  EXPECT_EQ(result1, result2);

  // Call with smaller value (should work with cached primes)
  int result3 = solution->prime_gap(40);
  EXPECT_GT(result3, 0);

  // Call with larger value
  int result4 = solution->prime_gap(100);
  EXPECT_GT(result4, 0);
}

// --- Test sequential access pattern ---
TEST_F(SolutionTest, SequentialAccessAscending) {
  std::vector<int> results;
  for (int i = 4; i <= 30; i += 2) {
    int gap = solution->prime_gap(i);
    EXPECT_GT(gap, 0) << "Failed for k = " << i;
    results.push_back(gap);
  }
  EXPECT_FALSE(results.empty());
}

// --- Comprehensive validation tests ---
TEST_F(SolutionTest, ComprehensiveValidationFirstHundred) {
  // Test various composite numbers in first 100
  std::vector<std::pair<int, int>> test_cases = {
      {4, 2},  // Between 3 and 5
      {6, 2},  // Between 5 and 7
      {8, 4},  // Between 7 and 11
      {9, 4},  // Between 7 and 11
      {10, 4}, // Between 7 and 11
      {12, 2}, // Between 11 and 13
      {14, 4}, // Between 13 and 17
      {20, 4}, // Between 19 and 23
      {24, 6}, // Between 23 and 29
      {50, 6}, // Between 47 and 53
      {90, 8}, // Between 89 and 97
  };

  for (const auto &[k, expected_gap] : test_cases) {
    EXPECT_EQ(solution->prime_gap(k), expected_gap) << "Failed for k = " << k;
  }
}
