/* 0020: Valid Parentheses */
#include "./utils/common.h"
#include <string>

class Solution {
public:
  /* O(n) */
  // stack
  bool isValid(string s) {
    stack<char> stack;
    for (auto x : s) {
      if (x == '{' || x == '[' || x == '(') {
        stack.push(x);
      } else {
        if (stack.size() == 0)
          return false;
        if (stack.top() == '(') {
          if (x != stack.top() + 1)
            return false;
        } else if (x != stack.top() + 2)
          return false;
        stack.pop();
      }
    }
    return stack.size() == 0;
  }
};

int main() {
  string s = "()";
  Solution sol;
  cout << sol.isValid(s) << endl;
  return 0;
}
