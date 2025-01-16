/* 0215: Kth Largest Element in an Array */
#include "utils/common.h"
#include <functional>

class Solution {
public:
  // minheap
  // nlogn
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < k; i++) {
      q.emplace(nums[i]);
    }
    for (int i = k; i < nums.size(); i++) {
      if (nums[i] > q.top()) {
        q.pop();
        q.emplace(nums[i]);
      }
    }

    return q.top();
  }

  // more direct
  int findKthLargest0(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> q;

    for (auto &x : nums) {
      q.emplace(x);
      if (q.size() > k) {
        q.pop();
      }
    }

    return q.top();
  }
};

int main() {
  vector<int> vec = {3, 2, 1, 5, 6, 4};
  Solution sol;
  cout << sol.findKthLargest0(vec, 2) << endl; // 5
}
