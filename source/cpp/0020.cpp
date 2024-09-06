/* 0020: Valid Parentheses */
#include "utils/common.h"

class Solution {
public:
  /* O(n) */
  // stack
  // not good structure
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

  // same method, but with a better code structure
  bool isValid2(string s) {
    stack<char> stack;
    for (auto x : s) {
      if (x == '(' || x == '[' || x == '{')
        stack.push(x);
      else {
        if (stack.empty())
          return false;
        if (x == ')' && stack.top() != '(')
          return false;
        if (x == ']' && stack.top() != '[')
          return false;
        if (x == '}' && stack.top() != '{')
          return false;
        stack.pop();
      }
    }
    return stack.empty();
  }

  // more sustainable solution with OCP: open for extension but closed for modification.
  // hashtable + stack
  bool isValid3(string s) {
    if (s.size() % 2 == 1)
      return false;
    stack<char> stack;
    // use hashmap to store the parentheses pairs. key: only closed brackets.
    unordered_map<char, char> pairs = {
        {')', '('}, {']', '['}, {'}', '{'} // the list can go on, like {'<','>'},{'\','/'}...
    };
    for (auto x : s) {
      // x is a legal key
      if (pairs.count(x)) {
        if (stack.empty() || stack.top() != pairs[x])
          return false;
        stack.pop();
      } else {
        stack.push(x);
      }
    }
    return stack.empty();
  }
};

int main() {
  string s1 = "()";    // true
  string s2 = "{{[)}"; // false
  Solution sol;
  cout << sol.isValid3(s1) << endl;
  cout << sol.isValid3(s2) << endl;
  return 0;
}

/* std::stack::empty(): true if empty; false if not. */
