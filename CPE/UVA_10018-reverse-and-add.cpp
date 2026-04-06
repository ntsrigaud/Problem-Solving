#include <iostream>

constexpr int MAX_ITERATIONS = 1000;

// UVa 10018 - Reverse and add

typedef struct Result {
	long long value = 0;
	long long iterations = 0;
	
	void display()const {
		std::cout << iterations << " " << value << '\n';
	};
} Result;

long long reverse_number(long long n);
long long reverse_add_number(long long n);
Result compute_palindrome(long long n);

int main () {
	int testcases = 0;
	long long p = 0;
	Result res; 
	
	std::cin >> testcases;
	
	for (int i = 0; i < testcases; ++i) {
		std::cin >> p;
		res = compute_palindrome(p);
		res.display();
	}
}

Result compute_palindrome(long long n) {
	// Reverse and add until palindrome found
	auto is_palindrome = [](long long value) -> bool {
    return value == reverse_number(value);
	};
	
	long long it_count = 0;
	long long candidate = n;
	while (++it_count <= MAX_ITERATIONS) {
		candidate = reverse_add_number(candidate);
		if (is_palindrome(candidate)) {
			return {candidate, it_count};
		}
	}
	
	return {0, 0};
}

long long reverse_number(long long n) {
	long long res = 0;
	
	while (n > 0) {
		long long mod = (n % 10);
		res = res *10 + mod;
    n /= 10;
	}
	
	return res;
}

long long reverse_add_number(long long n) {
	return reverse_number(n) + n;
}
