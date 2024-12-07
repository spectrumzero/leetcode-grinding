/* 0703: Kth Largest Element in a Stream */
#include "utils/common.h"

class KthLargest {
public:
  // Min Heap; Top k
  // log(n)
  priority_queue<int, vector<int>, greater<int>> q;
  int size;

  KthLargest(int k, vector<int> &nums) {
    this->size = k;
    for (auto &x : nums) {
      add(x);
    }
  }

  int add(int val) {
    q.push(val);
    if (q.size() > size) {
      q.pop();
    }
    return q.top();
  }
};

int main() {
  vector<int> nums = {4, 5, 8, 2};
  KthLargest *sol = new KthLargest(3, nums);
  cout << sol->add(3) << endl;  // 4
  cout << sol->add(5) << endl;  // 5
  cout << sol->add(10) << endl; // 5
  cout << sol->add(9) << endl;  // 8
  cout << sol->add(4) << endl;  // 8

  return 0;
}
