#include <iostream>
#include <string>

constexpr int MAX_ITERATIONS = 1000;

// Reverse and add

typedef struct Result {
	int value = 0;
	int iterations = 0;
	
	void display()const {
		std::cout << iterations << " " << value << '\n';
	};
} Result;

int reverse_number(int n);
int reverse_add_number(int n);
Result compute_palindrome(int n);

int main () {
	int testcases = 0;
	int p = 0;
	Result res; 
	
	std::cin >> testcases;
	
	for (int i = 0; i < testcases; ++i) {
		std::cin >> p;
		res = compute_palindrome(p);
		res.display();
	}
}

Result compute_palindrome(int n) {
	// Reverse and add until palindrome found
	auto is_palindrome = [](int value) -> bool {
		std::string str = std::to_string(value);
		int len = str.length();
		int mid = len / 2;
		
		for (int i = 0; i < mid; ++i) {
			if (str[i] != str[len - i - 1]) {
				return false;
			}
		}
		
		return true;
	};
	
	int it_count = 0;
	int candidate = n;
	while (++it_count <= MAX_ITERATIONS) {
		candidate = reverse_add_number(candidate);
		if (is_palindrome(candidate)) {
			return {candidate, it_count};
		}
	}
	
	return {0, 0};
}

int reverse_number(int n) {
	int res = 0;
	
	while (n > 0) {
		int mod = (n % 10);
		res = res *10 + mod;
    n /= 10;
	}
	
	return res;
}

int reverse_add_number(int n) {
	return reverse_number(n) + n;
}
