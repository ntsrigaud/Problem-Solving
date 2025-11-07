#include "solution.h"
#include <gtest/gtest.h>
#include <memory>
#include <string>
#include <vector>

// Test fixture for Solution
class SolutionTest : public ::testing::Test {
protected:
  std::unique_ptr<Solution> solution;
  void SetUp() override { solution = std::make_unique<Solution>(); }
};

// Helper: valid plate formatting is exactly 3 uppercase letters, '-', then 4
// digits
static bool is_valid_format(const std::string &s) {
  if (s.size() != 8)
    return false;
  for (int i = 0; i < 3; ++i)
    if (s[i] < 'A' || s[i] > 'Z')
      return false;
  if (s[3] != '-')
    return false;
  for (int i = 4; i < 8; ++i)
    if (s[i] < '0' || s[i] > '9')
      return false;
  return true;
}

TEST_F(SolutionTest, ValidFormatAcceptance) {
  // Valid formatted plates should return either "nice" or "not nice"
  std::vector<std::string> samples = {"ABC-0123", "AAA-0000", "ZZZ-9999",
                                      "KLM-0100"};
  for (auto &p : samples) {
    ASSERT_TRUE(is_valid_format(p));
    auto r = solution->nice_licence_plate(p);
    EXPECT_TRUE(r == "nice" || r == "not nice")
        << "unexpected result='" << r << "' for plate=" << p;
  }
}

TEST_F(SolutionTest, InvalidFormatRejected) {
  // Any deviation from 3 letters + '-' + 4 digits should yield a not-nice style
  // response
  std::vector<std::string> bad = {
      "AB-1234",   // left too short
      "ABCD-1234", // left too long
      "ABC-123",   // right too short
      "ABC-12345", // right too long
      "abc-1234",  // lowercase left
      "A1C-1234",  // digit in left
      "ABC_1234",  // wrong separator
      "ABC-12A4"   // non-digit in right
  };

  for (auto &p : bad) {
    auto r = solution->nice_licence_plate(p);
    // implementation uses "not nice" (or "not nice ...") for bad formats
    EXPECT_TRUE(r.rfind("not nice", 0) == 0)
        << "expected not nice prefix for plate=" << p << " got='" << r << "'";
  }
}

TEST_F(SolutionTest, ExactBoundaryChecks) {
  // Known exact checks derived from the problem definition
  // For AAA the left value is 0 -> difference = numeric value of right
  EXPECT_EQ(solution->nice_licence_plate("AAA-0100"), "nice");
  EXPECT_EQ(solution->nice_licence_plate("AAA-0101"), "not nice");

  // Another hand-checked example
  EXPECT_EQ(solution->nice_licence_plate("AAB-0001"), "nice");
}

TEST_F(SolutionTest, FullSweepSmallSet) {
  // Sweep a few left parts and some right parts to validate behaviour
  std::vector<std::string> lefts = {"AAA", "AAB", "ABC", "ZZZ"};
  std::vector<std::string> rights = {"0000", "0001", "0099",
                                     "0100", "0101", "9999"};

  for (auto &L : lefts)
    for (auto &R : rights) {
      std::string plate = L + "-" + R;
      ASSERT_TRUE(is_valid_format(plate));
      auto res = solution->nice_licence_plate(plate);
      EXPECT_TRUE(res == "nice" || res == "not nice")
          << "plate=" << plate << " res='" << res << "'";
    }
}
