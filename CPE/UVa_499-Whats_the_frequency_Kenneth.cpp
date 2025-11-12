#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/*
 * UVA: What's the Frequency, Kenneth?
 * Link: https://onlinejudge.org/external/4/499.pdf
 *
 * Revision history:
 * Originally written by Neil Taison Rigaud, November 2025
 * */

int main() {
  std::unordered_map<char, int> record;
  std::vector<char> res;
  std::string line;
  int max_freq = 0;

  while (std::getline(std::cin, line)) {
    max_freq = 0;
    res.clear();
    record.clear();

    for (const auto &letter : line) {
      if (!std::isalpha(letter))
        continue;

      record[letter]++;
      max_freq = (record[letter] > max_freq) ? record[letter] : max_freq;
    }

    if (!record.empty()) {
      for (const auto &p : record) {
        if (p.second == max_freq) {
          res.push_back(p.first);
        }
      }

      std::sort(res.begin(), res.end());
      line = std::string(res.begin(), res.end());
      std::cout << line << " " << max_freq << '\n';
    }
  }

  return 0;
}
