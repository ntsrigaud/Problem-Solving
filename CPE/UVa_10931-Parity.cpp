#include <iostream>
#include <string>

void solve(int n) {
  std::string bin = "";
  int mod = 0;
  int p = 0;

  // # Compute the binary value
  while (n > 0) {
    mod = n % 2;
    n /= 2;
    bin = std::to_string(mod) + bin;
    p += mod;
  }

  std::cout << "The parity of " << bin << " is " << p << " (mod 2).\n";
}

int main() {
  int n = 0;

  while (std::cin >> n && n != 0) {
    solve(n);
  }

  return 0;
}
