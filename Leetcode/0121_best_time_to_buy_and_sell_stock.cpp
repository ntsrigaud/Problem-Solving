// Leetcode # 121 - Best Time to Buy and Sell Stock

#include <algorithm>
#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int max_profit = 0;
    int min_price = prices.front();

    // Sliding window algorithm
    for (int new_price : prices) {
      if (new_price < min_price) {
        // Market fall
        min_price = new_price;
      } else {
        // Market rise
        max_profit = std::max(max_profit, new_price - min_price);
      }
    }

    return max_profit;
  }
};
