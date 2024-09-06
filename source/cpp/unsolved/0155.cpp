/* 0155: Min Stack */
#include "../utils/common.h"

class MinStack {
  /* O(1) */
  // stack (auxiliary stack)
private:
  std::stack<int> stack;
  // CORE: auxiliary stack which stores the minimum at the top. auxiliary stack + stack = full minstack.
  std::stack<int> minstack;

public:
  MinStack() {
    // for latter comparison
    minstack.push(INT_MAX);
  }

  void push(int val) {
    stack.push(val);
    // push after comparison
    minstack.push(min(val, minstack.top()));
  }

  void pop() {
    // Notice: minstack should be updated with stack regardless of poping or pushing. they should be understood as a pair.
    stack.pop();
    minstack.pop();
  }

  int top() { return stack.top(); }

  int getMin() { return minstack.top(); }
};

int main() {
  MinStack *st = new MinStack();
  st->push(0);
  st->push(-5);
  st->push(-2);
  st->push(9);
  st->pop();
  cout << st->top() << endl;    // -2
  cout << st->getMin() << endl; // -5
  return 0;
}
