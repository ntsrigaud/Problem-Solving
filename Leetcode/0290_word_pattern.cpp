// Leetcode #0290 - Word Pattern

#include <algorithm>
#include <sstream>
#include <string>
#include <unordered_map>

class Solution {
  struct Map {
    std::unordered_map<std::string, char> ch{0};
    std::unordered_map<char, std::string> str;
  };

public:
  bool wordPattern(std::string pattern, std::string s) {
    std::stringstream ss(s);
    std::vector<std::string> words;
    char cur_pattern = 0;
    char last_matched_char = 0;
    std::string cur_word;
    std::string last_matched_word;
    Map map;

    // Split the string first
    while (ss >> cur_word) {
      words.push_back(cur_word);
    }

    if (pattern.length() != words.size()) {
      return false;
    }

    // Cross-reference both maps
    for (size_t i = 0; i < pattern.size(); ++i) {
      cur_pattern = pattern.at(i);
      cur_word = words.at(i);

      auto word_it = map.str.find(cur_pattern);
      auto char_it = map.ch.find(cur_word);

      last_matched_word = word_it != map.str.end() ? word_it->second : "";
      last_matched_char = char_it != map.ch.end() ? char_it->second : 0;

      if ((!last_matched_word.empty() && last_matched_word != cur_word) ||
          (last_matched_char != 0 && last_matched_char != cur_pattern)) {
        return false;
      }

      if (last_matched_word.empty()) {
        map.str[cur_pattern] = cur_word;
      }

      if (last_matched_char == 0) {
        map.ch[cur_word] = cur_pattern;
      }
    }

    return true;
  }
};
