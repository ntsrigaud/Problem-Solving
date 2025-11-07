#include "solution.h"
#include <gtest/gtest.h>
#include <memory>

struct SolutionTest : public ::testing::Test {
    std::unique_ptr<Solution> solution;

    void SetUp() override { solution = std::make_unique<Solution>(); }
    void TearDown() override {}
};

// ============================================================================
// BASIC FUNCTIONALITY TESTS
// ============================================================================

TEST_F(SolutionTest, BasicExampleWalkingDown) {
    // Example from the problem description
    StrPair input = {"walking", "down"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "nw");
}

TEST_F(SolutionTest, SimpleCommonCharacters) {
    StrPair input = {"abc", "bca"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "abc");
}

TEST_F(SolutionTest, PartialOverlap) {
    StrPair input = {"hello", "world"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "lo");
}

TEST_F(SolutionTest, SingleCommonCharacter) {
    StrPair input = {"abc", "xyz"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "");
}

TEST_F(SolutionTest, AllCharactersCommon) {
    StrPair input = {"test", "test"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "estt");
}

// ============================================================================
// EDGE CASES
// ============================================================================

TEST_F(SolutionTest, EmptyFirstString) {
    StrPair input = {"", "hello"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "");
}

TEST_F(SolutionTest, EmptySecondString) {
    StrPair input = {"hello", ""};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "");
}

TEST_F(SolutionTest, BothStringsEmpty) {
    StrPair input = {"", ""};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "");
}

TEST_F(SolutionTest, NoCommonCharacters) {
    StrPair input = {"abc", "xyz"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "");
}

TEST_F(SolutionTest, DisjointCharacterSets) {
    StrPair input = {"abcdef", "ghijkl"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "");
}

// ============================================================================
// BOUNDARY CONDITIONS
// ============================================================================

TEST_F(SolutionTest, SingleCharacterStringsSame) {
    StrPair input = {"a", "a"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "a");
}

TEST_F(SolutionTest, SingleCharacterStringsDifferent) {
    StrPair input = {"a", "b"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "");
}

TEST_F(SolutionTest, OneCharacterVsLongString) {
    StrPair input = {"a", "banana"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "a");
}

TEST_F(SolutionTest, LongStringVsOneCharacter) {
    StrPair input = {"banana", "a"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "a");
}

// ============================================================================
// CHARACTER COUNTING TESTS
// ============================================================================

TEST_F(SolutionTest, RepeatedCharactersSameCounts) {
    StrPair input = {"aaa", "aaa"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "aaa");
}

TEST_F(SolutionTest, RepeatedCharactersDifferentCounts) {
    StrPair input = {"aaaa", "aa"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "aa");
}

TEST_F(SolutionTest, RepeatedCharactersFirstHasLess) {
    StrPair input = {"aa", "aaaa"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "aa");
}

TEST_F(SolutionTest, MultipleRepeatedCharacters) {
    StrPair input = {"aabbcc", "abcabc"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "aabbcc");
}

TEST_F(SolutionTest, ComplexCharacterCounting) {
    StrPair input = {"programming", "algorithm"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "agimor");
}

TEST_F(SolutionTest, MixedCharacterCounts) {
    StrPair input = {"mississippi", "misses"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "imsss");
}

// ============================================================================
// ALPHABETICAL ORDERING TESTS
// ============================================================================

TEST_F(SolutionTest, AlphabeticalOrderReverseInput) {
    StrPair input = {"zyx", "xyz"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "xyz");
}

TEST_F(SolutionTest, AlphabeticalOrderRandomInput) {
    StrPair input = {"random", "modern"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "dmnor");
}

TEST_F(SolutionTest, AlphabeticalOrderComplexCase) {
    StrPair input = {"software", "flowchart"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "afortw");
}

// ============================================================================
// SPECIAL PATTERN TESTS
// ============================================================================

TEST_F(SolutionTest, PalindromeStrings) {
    StrPair input = {"racecar", "carrace"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "aaccerr");
}

TEST_F(SolutionTest, AnagramStrings) {
    StrPair input = {"listen", "silent"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "eilnst");
}

TEST_F(SolutionTest, SubstringRelation) {
    StrPair input = {"programming", "program"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "agmoprr");
}

TEST_F(SolutionTest, OneStringIsSubsetOfAnother) {
    StrPair input = {"abcdef", "ace"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "ace");
}

// ============================================================================
// STRESS TESTS WITH LONGER STRINGS
// ============================================================================

TEST_F(SolutionTest, LongerStringsPartialOverlap) {
    StrPair input = {
        "thequickbrownfoxjumpsoverthelazydog",
        "packmyboxwithfivedozenliquorjugs"
    };
    std::string result = solution->common_permutation(input);
    // First string is a pangram (contains all letters a-z), so result will be 
    // all letters from second string sorted alphabetically
    EXPECT_EQ(result, "abcdeefghijklmnooopqrstuuvwxyz");
}

TEST_F(SolutionTest, LongerStringsMostlyCommon) {
    std::string long_str1 = "abcdefghijklmnopqrstuvwxyz";
    std::string long_str2 = "zyxwvutsrqponmlkjihgfedcba";
    StrPair input = {long_str1, long_str2};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "abcdefghijklmnopqrstuvwxyz");
}

TEST_F(SolutionTest, RepeatedPattern) {
    StrPair input = {"abcabc", "defdef"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "");
}

TEST_F(SolutionTest, AlternatingPattern) {
    StrPair input = {"ababab", "bababa"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "aaabbb");
}

// ============================================================================
// BOUNDARY VALUE TESTS
// ============================================================================

TEST_F(SolutionTest, MaxLengthSingleCharacter) {
    std::string str1000(1000, 'a');
    std::string str500(500, 'a');
    StrPair input = {str1000, str500};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, str500);
}

TEST_F(SolutionTest, AlphabetEdgeCasesFirstLetter) {
    StrPair input = {"axaxax", "ayaya"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "aaa");
}

TEST_F(SolutionTest, AlphabetEdgeCasesLastLetter) {
    StrPair input = {"zxzxzx", "zyzy"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "zz");
}

// ============================================================================
// ERROR HANDLING AND ROBUSTNESS TESTS
// ============================================================================

TEST_F(SolutionTest, VeryLongStringsNoCommon) {
    std::string str1(500, 'a');
    std::string str2(500, 'b');
    StrPair input = {str1, str2};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "");
}

TEST_F(SolutionTest, InterleavedCommonCharacters) {
    StrPair input = {"abababab", "babababa"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "aaaabbbb");
}

TEST_F(SolutionTest, ConsequentialCharacters) {
    StrPair input = {"abcdefghij", "jihgfedcba"};
    std::string result = solution->common_permutation(input);
    EXPECT_EQ(result, "abcdefghij");
}
