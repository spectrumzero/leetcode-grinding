/* 0150: Evaluate Reverse Polish Notation */
#include "utils/common.h"
#include <string>

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> st;
    unordered_set<string> set = {"+", "-", "*", "/"};
    for (auto x : tokens) {
      // number
      if (!set.count(x)) {
        // type conversion
        int num = atoi(x.c_str());
        // push
        st.push(num);
      }
      // operation
      else {
        int num1 = st.top();
        st.pop();
        // next top
        int num2 = st.top();
        st.pop();
        // update; new top
        if (x == "+")
          st.push(num2 + num1);
        if (x == "-")
          st.push(num2 - num1);
        if (x == "*")
          st.push(num2 * num1);
        if (x == "/")
          st.push(num2 / num1);
      }
    }
    // top = result
    return st.top();
  }
};

int main() {
  vector<string> s = {"4", "13", "5", "/", "+"};
  class Solution sol;
  cout << sol.evalRPN(s) << endl; // 6
  return 0;
}

/* NOTE:
 * int num = atoi(x.c_str());
 * 1: std::string::c_str(): Returns a pointer to a null-terminated character array with data equivalent to those stored in the string.
 * 2: std::atoi(const char* str): Transform characters into an integer and return it. you should have noticed that the parameter list only receives the pointer pointing to a character array. So the step one is necessary.
 * eg: '42' -> 42; '31337 with words' -> 31337; '0x2a' -> 0;
 */
