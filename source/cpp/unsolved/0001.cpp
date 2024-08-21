/* 0001: Two Sum */
#include "../utils/common.h"
#include <cstdio>

class Solution {
public:
  /* O(n) */
  vector<int> twoSumhashtable(vector<int> &nums, int target) {
    // key: the element of nums; value: the index of nums;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      // records traversing information while traversing to save time complexity
      // check whether the value corresponding to the key (the passed argument) exists in the map and return an iterator
      auto search = map.find(target - nums[i]);
      if (search != map.end()) {
        return {i, search->second};
      }
      map[nums[i]] = i;
    }
    // not found
    return {};
  }

  /* O(n) */
  // two-pass hashtable
  vector<int> twoSumtwopass(vector<int> &nums, int target) {
    unordered_map<int, int> numMap;
    int n = nums.size();

    // Build the hash table
    for (int i = 0; i < n; i++) {
      numMap[nums[i]] = i;
    }

    // Find the complement
    for (int i = 0; i < n; i++) {
      int complement = target - nums[i];
      // unordered_map::count: check whether the value corresponding to the key (complement here) exists in the map and return 1 (found) or 0 (not found)
      // ensure every element of nums is used only once
      if (numMap.count(complement) && numMap[complement] != i) {
        return {i, numMap[complement]};
      }
    }

    return {}; // No solution found
  }
};

int main() {
  vector<int> nums = {1, 2, 2, 3, 4, 7};
  Solution sol;
  vector<int> res2 = sol.twoSumhashtable(nums, 10); //[5,3]
  vector<int> res = sol.twoSumtwopass(nums, 10);    //[3,5]
  cout << "[ " << res[0] << "," << res[1] << " ]" << endl;
  cout << "[ " << res2[0] << "," << res2[1] << " ]" << endl;
}
