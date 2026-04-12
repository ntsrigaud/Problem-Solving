#include <iostream>
#include <vector>

// UVa12503: Robot instructions

void solve() {
  int n;
  int position = 0;

  std::vector<int> record;
  std::cin >> n;

  record.reserve(n);

  for (int i = 0; i < n; ++i) {
    std::string op;
    std::cin >> op;

    if (op == "LEFT") {
      record.push_back(-1);
      position -= 1;
    } else if (op == "RIGHT") {
      record.push_back(1);
      position += 1;
    } else if (op == "SAME") {
      std::string as;
      int idx;

      std::cin >> as >> idx;

      int move_value = record[idx - 1];
      record.push_back(move_value);
      position += move_value;
    }
  }

  std::cout << position << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int testcases = 0;
  if (std::cin >> testcases) {
    while (testcases--) {
      solve();
    }
  }

  return 0;
}
