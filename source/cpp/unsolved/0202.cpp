/* 0202: Happy Number */
#include "../utils/common.h"

class Solution {
public:
  /* O(logn) */
  // hashtable
  // break things down: figure out the sum of the square of each digit in a number;
  int newsum(int n) {
    int sum = 0;
    int square = 0;
    while (n > 0) {
      square = n % 10;
      sum += square * square;
      // logn here
      n = n / 10;
    }
    return sum;
  }

  bool isHappy(int n) {
    // Core: use hashset to check whether there is duplicate element (the sum). If any, then it means the infinite cycle happened. Return false.
    // thus it is actually a repetition problem, an algorithm problem, not a math problem.
    unordered_set<int> set;
    int nextsum = newsum(n);
    while (nextsum != 1) {
      if (set.find(nextsum) != set.end()) {
        return false;
      }
      set.insert(nextsum);
      nextsum = newsum(nextsum);
    }
    return true;
  }
};

int main() {
  Solution sol;
  cout << sol.isHappy(19) << endl;  // true
  cout << sol.isHappy(91) << endl;  // true
  cout << sol.isHappy(101) << endl; // false
  return 0;
}
