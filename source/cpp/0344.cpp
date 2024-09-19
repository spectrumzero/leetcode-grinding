/* 0344: Reverse String */
#include "utils/common.h"

class Solution {
public:
  // Two Pointers
  // O(n)
  void reverseString(vector<char> &s) {
    int size = s.size();
    int left = 0;
    int right = size - 1;
    while (left < right) {
      char tmp = s[left];
      s[left] = s[right];
      s[right] = tmp;
      left++;
      right--;
    }
  }
};

int main() {
  vector<char> s = {'h', 'e', 'l', 'l', 'o'};
  Solution sol;
  sol.reverseString(s); // ['o','l','l','e','h']
  printVector(s);
  return 0;
}
