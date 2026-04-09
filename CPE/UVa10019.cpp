#include <iostream>

// UVa10019: Funny Encryption Method

int count_1s(int n, int base = 10);

void solve(int n) {
  int b1 = count_1s(n);
  int b2 = count_1s(n, 16);

  std::cout << b1 << ' ' << b2 << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N = 0;
  int test_case = 0;

  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    std::cin >> test_case;
    solve(test_case);
  }

  return 0;
}

int count_1s(int n, int base) {
  int count = 0;

  auto get_hex_count = [](int n) -> int {
    switch (n) {
    case 0:
      return 0;
    case 1:
      return 1;
    case 2:
      return 1;
    case 3:
      return 2;
    case 4:
      return 1;
    case 5:
      return 2;
    case 6:
      return 2;
    case 7:
      return 3;
    case 8:
      return 1;
    case 9:
      return 2;
    default:
      return 0;
    }
  };

  if (base == 10) {
    while (n > 0) {
      count += n % 2;
      n /= 2;
    }
  } else {
    // Hexadecimal
    while (n > 0) {
      count += get_hex_count(n % 10);
      n /= 10;
    }
  }

  return count;
}
