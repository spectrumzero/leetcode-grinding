/* 0027: Remove Element */
#include "utils/common.h"

class Solution {
public:
  // Single Pointer
  // O(n)
  int removeElement(vector<int> &nums, int val) {
    int size = nums.size();
    int left = 0;
    for (auto x : nums) {
      if (x != val) {
        nums[left] = x;
        left++;
      }
    }
    return left;
  }

  // Two Pointers
  // O(n)
  int removeElement_2(vector<int> &nums, int val) {
    int size = nums.size();
    // slow pointer
    int left = 0;
    // fast pointer: right
    for (int right = 0; right < size; right++) {
      if (nums[right] != val) {
        nums[left] = nums[right];
        // move forward simultaneously
        left++;
      }
      // only move fast pointer
    }
    return left;
  }

  // improved Two Pointers
  // O(n)
  int removeElement_3(vector<int> &nums, int val) {
    int size = nums.size();
    // start
    int left = 0;
    // end
    int right = size - 1;
    // ensure all elements are checked
    while (left <= right) {
      if (nums[left] != val) {
        left++;
      } else {
        nums[left] = nums[right];
        right--;
      }
    }
    return left;
  }
};

int main() {
  vector<int> nums = {3, 2, 2, 3};
  Solution sol;
  sol.removeElement_2(nums, 3); // [2,2,_,_]
  printVector(nums);
  return 0;
}
