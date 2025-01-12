/* 1046: Last Stone Weight */
#include "utils/common.h"

class Solution {
public:
  // Maxheap
  // nlogn
  int lastStoneWeight(vector<int> &stones) {
    priority_queue<int, vector<int>, less<int>> q;
    for (auto &x : stones) {
      q.push(x);
    }

    while (q.size() > 1) {
      int largest = q.top();
      q.pop();
      int seclargest = q.top();
      q.pop();
      if (largest != seclargest) {
        q.push(largest - seclargest);
      }
    }

    return q.empty() ? 0 : q.top();
  }
};

int main() {
  vector<int> vec = {2, 7, 4, 1, 8, 1};
  Solution sol;
  cout << sol.lastStoneWeight(vec) << endl; // 1
}
