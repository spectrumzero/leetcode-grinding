/* 0153: Find Minimum in Rotated Sorted Array */
#include "utils/common.h"

class Solution {
public:
  int findMin(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] < nums[right]) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return nums[right];
  }
};

int main() {
  vector<int> vec = {3, 4, 5, 1, 2};
  Solution sol;
  cout << sol.findMin(vec) << endl; // 1
  return 0;
}
