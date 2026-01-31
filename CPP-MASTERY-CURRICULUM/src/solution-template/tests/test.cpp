#include "solution.h"
#include <gtest/gtest.h>
#include <memory>

struct SolutionTest : public ::testing::Test {
    std::unique_ptr<Solution> solution;

    void SetUp() override { solution = std::make_unique<Solution>(); }
    void TearDown() override {}
};

// --- Example test ---
TEST_F(SolutionTest, SampleTest) {
    ASSERT_TRUE(true); // Replace with real tests
}
