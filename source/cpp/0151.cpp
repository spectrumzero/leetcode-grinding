/* 0151: Reverse Words in a String */

#include "utils/common.h"

class Solution {
public:
  // O(n)
  // Two Pointers
  string reverseWords(string s) {
    int size = s.size();
    int right = size - 1;
    string res;
    for (int left = right; left >= 0; left--) {
      if (s[left] == ' ') {
        right--;
      } else {
        // record the index range of a valid word with no space: [start, right]
        while (left >= 0 && s[left] != ' ') {
          left--;
        }
        // left < -1 or s[left] == ' ' (a space character).
        for (int start = left + 1; start <= right; start++) {
          // push characters in the index range of [start, right] into the result while keeping the correct order.
          res.push_back(s[start]);
        }
        // space as a separater between words.
        res.push_back(' ');
        // dont forget to update the slow pointer to ensure two pointers are at the same position in the next iteration.
        right = left;
        right--;
      }
    }
    // abandon the last redundant ' '.
    res.pop_back();
    return res;
  }
};

int main() {
  string s = "blue is sky the"; // the sky is blue
  Solution sol;
  string res = sol.reverseWords(s);
  cout << res << endl;
  return 0;
}
