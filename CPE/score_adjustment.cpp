#include <iostream>
#include <cmath>
#include <vector>

int adjust_score(int score, int min, int max) {
	if (max == min) return 100;
		
	// Linear interpolation
	double adjusted = 60.0 + 40.0 * (score - min) / (max - min);
	return std::round(adjusted);
}

int main() {
	int score = 0;
	int min = 100;
	int max = 0;
	std::vector<int> scores;
	 
	while (std::cin >> score) {
		scores.push_back(score);
		if (score < min) { min = score; }
		if (score > max) { max = score; }
	}
	
	if (scores.empty()) return 0;
	
	for (int s: scores) {
		std::cout << adjust_score(s, min, max) << '\n';
	}
	 
	return 0;
}
