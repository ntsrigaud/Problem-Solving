#include "solution.h"

// Implement problem-specific methods here
int Solution::sum(int arr[], int size) const {
  int sum = 0;
  
  for (int i = 0; i < size; ++i) {
    sum += arr[i];
  }

  return sum;
}

double Solution::average(int arr[], int size) const {
  return sum(arr, size) / size;
};
