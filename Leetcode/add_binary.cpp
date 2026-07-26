#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    int carry = 0;

    auto add_bits = [&](char a, char b) -> char {
      int res = (a - '0') + (b - '0') + carry;
      carry = (res < 2) ? 0 : 1;
      return (res % 2) + '0';
    };

    int max_len = std::max(a.size(), b.size());
    int i = 0;

    // Normalize both strings
    if (a.size() < max_len) {
      a.insert(0, max_len - a.size(), '0');
    } else if (b.size() < max_len) {
      b.insert(0, max_len - b.size(), '0');
    }

    i = 0;
    string res;
    while (max_len - i - 1 >= 0) {
      res = add_bits(a.at(max_len - i - 1), b.at(max_len - i - 1)) + res;
      ++i;
    }

    if (carry) {
      res.insert(0, 1, carry + '0');
    }

    return res;
  }
};

int main() {
  Solution sol;

  std::string a = "11", b = "1";
  std::cout << "Result: " << sol.addBinary(a, b);

  return 0;
}
