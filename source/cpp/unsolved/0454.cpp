/* 0454: 4Sum II */
#include "utils/common.h"

class Solution {
public:
  /* O(n^2) */
  // hashtable
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
    unordered_map<int, int> countAB;
    int res = 0;
    // initialization
    for (auto a : nums1) {
      for (auto b : nums2) {
        countAB[a + b]++;
      }
    }
    // final result
    for (auto c : nums3) {
      for (auto d : nums4) {
        // either 1 or 0
        if (countAB.count(-(c + d))) {
          // add directly
          res += countAB[-(c + d)];
        }
      }
    }
    return res;
  }
};

int main() {
  vector<int> nums1 = {0, 0};
  vector<int> nums2 = {0, 1}; // map[0] = 3; map[1] = 1
  vector<int> nums3 = {0, -1};
  vector<int> nums4 = {5, 0};
  Solution sol;
  // R: return the number of triplets
  cout << sol.fourSumCount(nums1, nums2, nums3, nums4) << endl; // 1*3+1*1=4
  return 0;
}
