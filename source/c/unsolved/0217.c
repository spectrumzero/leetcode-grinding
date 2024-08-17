/* 0217: Contains Duplicate*/

#include "../utils/common.h"

/* O(n^2): */
bool containsDuplicate(int *nums, int numsSize) {
  for (int i = 0; i < numsSize - 1; i++) {
    for (int j = i + 1; j < numsSize; j++)
      if (nums[i] == nums[j]) {
        return true;
      }
  }
  return false;
}

/* O(nlogn): */
// Use const to ensure the pointers _a and _b point to data that should not be modified within the function
// But the pointers themselves can be modified.
int compar(const void *_a, const void *_b) {
  int a = *((int *)_a);
  int b = *((int *)_b);
  return a - b;
}

bool containsDuplicate2(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), compar);
  // traverse the sorted array
  for (int i = 0; i < numsSize - 1; i++) {
    if (nums[i] == nums[i + 1]) {
      return true;
    }
  }
  return false;
}

int main() {
  int nums[] = {2, 4, 5, 9, 8, 9}; // true
  int numsSize = sizeof(nums) / sizeof(int);
  printf("%d", containsDuplicate2(nums, numsSize));
  return 0;
}
