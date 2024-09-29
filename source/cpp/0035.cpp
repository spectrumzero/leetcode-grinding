/* 0035: Search Insert Position */
#include "utils/common.h"

class Solution {
public:
  // Binary Search
  // O(logn)
  int searchInsert(vector<int> &nums, int target) {
    int size = nums.size();
    int left = 0, right = size - 1, mid = left + (right - left) / 2;
    while (left <= right) {
      if (target == nums[mid]) {
        return mid;
      } else if (target < nums[mid]) {
        right = mid - 1;
        mid = left + (right - left) / 2;
      } else {
        left = mid + 1;
        mid = left + (right - left) / 2;
      }
    }

    if (mid > size - 1) {
      return mid;
    } else {
      return target > nums[mid] ? mid + 1 : mid;
    }
  }

  // more brief:
  int searchInsert2(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1, mid = left + (right - left) / 2;
    while (left <= right) {
      if (target == nums[mid]) {
        return mid;
      } else if (target > nums[mid]) {
        left = mid + 1;
        mid = left + (right - left) / 2;
      } else {
        right = mid - 1;
        mid = left + (right - left) / 2;
      }
    }
    return left;
  }
};

int main() {
  vector<int> nums = {1, 3, 4, 7, 9, 12, 17, 20};
  Solution sol;
  cout << sol.searchInsert(nums, 5) << endl; // 3
  return 0;
}
