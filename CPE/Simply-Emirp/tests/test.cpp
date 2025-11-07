#include "solution.h"
#include <gtest/gtest.h>
#include <memory>
#include <vector>

struct SolutionTest : public ::testing::Test {
  std::unique_ptr<Solution> solution;

  void SetUp() override { solution = std::make_unique<Solution>(); }
  void TearDown() override {}
};

using TestCase = std::vector<std::pair<int, std::string>>;

// --- Example test ---
TEST_F(SolutionTest, SampleTest) {
  TestCase samples{
      {17, "emirp"},  {18, "not prime"}, {19, "prime"},
      {179, "emirp"}, {199, "emirp"},
  };

  for (const auto &[input, expected] : samples) {
    const auto result = solution->classify_prime(input);
    EXPECT_EQ(result, expected)
        << "Input: " << input << " | Expected: " << expected
        << " | Got: " << result;
  }
}

// --- Additional tests ---
TEST_F(SolutionTest, EdgeAndPalindromicPrimes) {
  TestCase cases{
      {0, "not prime"}, {1, "not prime"}, {-7, "not prime"}, {2, "prime"},
      {3, "prime"},     {5, "prime"},     {11, "prime"}, // palindromic prime ->
                                                         // not emirp by
                                                         // definition
      {101, "prime"},                                    // palindromic prime
      {131, "prime"},                                    // palindromic prime
  };

  for (const auto &[input, expected] : cases) {
    const auto result = solution->classify_prime(input);
    EXPECT_EQ(result, expected)
        << "Input: " << input << " | Expected: " << expected
        << " | Got: " << result;
  }
}

TEST_F(SolutionTest, EmirpAndNonEmirpPrimes) {
  TestCase cases{
      // Known small emirps
      {13, "emirp"}, // 13 <-> 31
      {17, "emirp"}, // already tested above but include again
      {31, "emirp"}, // reverse of 13
      {37, "emirp"}, // 37 <-> 73

      // Primes whose reverse is composite (explicit NonEmirp cases)
      {23, "prime"}, // reverse 32 not prime
      {29, "prime"}, // reverse 92 not prime
      {41, "prime"}, // reverse 14 not prime
      {43, "prime"}, // reverse 34 not prime
      {59, "prime"}, // reverse 95 not prime
      {83, "prime"}, // reverse 38 not prime

      // Larger numbers
      {1009, "emirp"},  // 1009 is prime, reverse 9001 is also prime
      {1061, "emirp"},  // 1061 <-> 1601 both prime
      {10007, "emirp"}, // 10007 <-> 70001 both prime
  };

  for (const auto &[input, expected] : cases) {
    const auto result = solution->classify_prime(input);
    EXPECT_EQ(result, expected)
        << "Input: " << input << " | Expected: " << expected
        << " | Got: " << result;
  }
}

TEST_F(SolutionTest, CompositeNumbers) {
  TestCase cases{{4, "not prime"},
                 {15, "not prime"},
                 {100, "not prime"},
                 {10201, "not prime"}}; // 10201 = 101*101

  for (const auto &[input, expected] : cases) {
    const auto result = solution->classify_prime(input);
    EXPECT_EQ(result, expected)
        << "Input: " << input << " | Expected: " << expected
        << " | Got: " << result;
  }
}
