#include <iostream>

using StrPair = std::pair<std::string, std::string>;

std::string common_permutation(const StrPair &inputs) const {

  // Records the characters and their count number.
  auto map_letters =
      [&](const std::string &input) -> std::unordered_map<char, int> {
    std::unordered_map<char, int> record;
    for (char c : input) {
      record[c]++;
    }
    return record;
  };

  // Get the longest subsequence from the pair of strings
  auto get_sub = [&](const StrPair &in) -> std::string {
    std::string sub;
    auto rec = map_letters(in.first);

    for (char c : in.second) {
      if (rec.count(c) > 0 && rec[c] > 0) {
        sub += c;
        --rec[c];
      }
    }

    return sub;
  };

  // Main procedure calling and sorting
  auto l_sub = get_sub(inputs);
  auto comp = [](char a, char b) -> bool { return a < b; };
  std::sort(l_sub.begin(), l_sub.end(), comp);
  return l_sub;
};

int main() {
  // TODO: Update main program logic to fit OJ input
  try {
    // Main program logic here
    StrPair in;
    while (std::cin >> in.first && std::cin >> in.second) {
      std::cout << common_permutation(in) << '\n';
    }
  } catch (const std::invalid_argument &e) {
    std::cerr << "Error: " << e.what() << "\n";
  }

  return 0;
}
