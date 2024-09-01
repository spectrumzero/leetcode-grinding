/* 0349: Intersection of Two Arrays */
#include "./utils/common.h"

class Solution {
public:
  /* O(n) */
  // hashtable
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> map;
    // initialization
    for (auto &k : nums1) {
      map[k] = 0;
    }
    // update
    for (auto &k : nums2) {
      if (map.find(k) != map.end()) {
        map[k] = 1;
      }
    }
    // output
    // Notice: Avoid using res[i] when the vector starts empty as below, which will lead to out-of-bounds error. Use push_back() instead.
    vector<int> res;
    for (auto &k : map) {
      if (k.second == 1) {
        res.push_back(k.first);
      }
    }
    return res;
  }

  /* O(n) */
  // similar: two hash_sets
  vector<int> intersectionsimilar(vector<int> &nums1, vector<int> &nums2) {
    // result after updating
    unordered_set<int> result_set;
    // a convenient way of declaring a hash set that stores unique integers in a vector
    // {2,3,1} => {2,3,1}
    unordered_set<int> nums_set(nums1.begin(), nums1.end());
    for (int num : nums2) {
      // updating rules
      if (nums_set.find(num) != nums_set.end()) {
        result_set.insert(num);
      }
    }

    // a convenient way of declaring a vector that stores unique integers in a hash_set. COOL.
    // {2,3,1} => {2,3,1}
    return vector<int>(result_set.begin(), result_set.end());
  }
};

int main() {
  vector<int> nums1 = {5, 7, 2, 9};
  vector<int> nums2 = {9, 7};
  Solution sol;
  // R: each element in the result must be unique
  vector<int> res = sol.intersection(nums1, nums2); //[9,7]
  // vector<int> res = sol.intersectionsimilar(nums1, nums2); //[7,9]
  cout << "[";
  for (int i = 0; i < res.size() - 1; i++) {
    cout << res[i] << ",";
  }
  cout << res[res.size() - 1] << "]";
  return 0;
}
