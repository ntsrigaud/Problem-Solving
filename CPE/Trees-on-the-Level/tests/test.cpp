#include "solution.h"
#include <gtest/gtest.h>
#include <memory>
#include <sstream>
#include <string>
#include "util.h"

struct SolutionTest : public ::testing::Test {
  std::unique_ptr<Solution> solution;

  void SetUp() override { solution = std::make_unique<Solution>(); }
  void TearDown() override {}
};

// --- Example test ---
TEST_F(SolutionTest, SampleTest) {
  // Basic functional test using helper.
  const std::string input = "(1,)(2,L)(3,R)()";
  const std::string out = runSolution(input);
  ASSERT_TRUE(out == "1 2 3 \n");
}

TEST_F(SolutionTest, EmptyInputReturnsEmpty) {
  // Input with only terminator should be considered end-of-input and produce no output
  const std::string out = runSolution("()");
  ASSERT_TRUE(out.empty());
}

TEST_F(SolutionTest, MissingHeadThrows) {
  // Nodes with positions but no head node should throw
  ASSERT_THROW(runSolution("(2,L)(3,R)()"), std::invalid_argument);
}

TEST_F(SolutionTest, DuplicateValueProducesNotComplete) {
  // Duplicate node values among non-head nodes should mark the tree as not completely specified
  const std::string out = runSolution("(1,)(2,L)(2,R)()");
  ASSERT_TRUE(out == "1 2 2 \nnot complete\n");
}

TEST_F(SolutionTest, PositionCollisionThrows) {
  // Two nodes targetting the same position should cause a runtime error
  ASSERT_THROW(runSolution("(1,)(2,L)(3,L)()"), std::runtime_error);
}

TEST_F(SolutionTest, HeadDuplicateProducesNotComplete) {
  // Duplicate value between head and a child should mark tree as not complete
  const std::string out = runSolution("(1,)(1,L)()");
  ASSERT_TRUE(out == "1 1 \nnot complete\n");
}

TEST_F(SolutionTest, ComplexTreeOrder) {
  // Nodes added in arbitrary order should still build correct tree
  const std::string input = "(1,)(3,L)(2,R)(5,RR)(4,RL)()";
  const std::string out = runSolution(input);
  ASSERT_TRUE(out == "1 3 2 4 5 \n");
}

TEST_F(SolutionTest, DeepLeftChain) {
  // Deep left chain
  const std::string input = "(10,)(9,L)(8,LL)(7,LLL)()";
  const std::string out = runSolution(input);
  ASSERT_TRUE(out == "10 9 8 7 \n");
}

TEST_F(SolutionTest, ChildBeforeParent) {
  // Children may appear before their parent in input; insertion sorts by path length
  const std::string input = "(4,LL)(2,L)(1,)(3,R)()";
  const std::string out = runSolution(input);
  ASSERT_TRUE(out == "1 2 3 4 \n");
}

TEST_F(SolutionTest, PerfectTreeShuffled) {
  // Perfect binary tree nodes provided in shuffled order
  const std::string input = "(4,LL)(2,L)(7,RR)(3,R)(1,)(5,LR)(6,RL)()";
  const std::string out = runSolution(input);
  ASSERT_TRUE(out == "1 2 3 4 5 6 7 \n");
}

TEST_F(SolutionTest, UvaOfficialSamples) {
  // Combined multi-tree stream (first: duplicate head -> not complete,
  // second: simple tree)
  const std::string input = "(1,)(1,L)()(1,)(2,L)(3,R)()()";
  const std::string out = runSolution(input);
  const std::string expected = "1 1 \nnot complete\n1 2 3 \n";
  ASSERT_TRUE(out == expected);
}
