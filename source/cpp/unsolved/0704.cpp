/* 0704: Binary Search */

#include "utils/common.h"
#include <vector>

class Solution {
public:
  // O(logn)
  // Binary Search
  int search(vector<int> &nums, int target) {
    int size = nums.size();
    int left = 0;
    int right = size - 1;
    // the nums[mid] is the core of traversing
    while (left <= right) {
      // [left, mid, right] => mid = left+(right-left)/2
      // always remember to update the actual mid.
      int mid = left + (right - left) / 2;
      if (target == nums[mid]) {
        return mid;
      } else if (target < nums[mid]) {
        // given that the elements of nums are in ascending order, the target must be on the left side. keep the left endpoint and update the right endpoint.
        right = mid - 1;
      } else {
        // similar logic: keep the right endpoint and update the left endpoint
        left = mid + 1;
      }
    }
    // no found
    return -1;
  }
};

int main() {
  vector<int> nums = {0, 2, 3, 4, 9};
  Solution sol;
  cout << sol.search(nums, 3) << endl; // 2
  return 0;
}
