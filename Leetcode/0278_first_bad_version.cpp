// Leetcode #0278 - First Bad Version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    if (n == 1) {
      return 1;
    }

    // Binary search to minimize API calls
    int low = 1;
    int high = n;
    int median = 0;

    while (high - low > 1) {
      median = low + ((high - low) / 2);

      if (isBadVersion(median)) {
        high = median;
      } else {
        low = median;
      }
    }

    return isBadVersion(low) ? low : high;
  }
};
