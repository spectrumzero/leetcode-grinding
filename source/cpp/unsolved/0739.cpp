/* 0739: Daily Temperatures */
#include "utils/common.h"

class Solution {
public:
  // O (n*n)
  // BAD stack method leading to LTE errors.
  // though the issue is purely about efficiency instead of correctness, you should not use this method because it can handle very large input poorly.
  // in brief, O(n*n) is WRONG. you have to consider and reduce the time complexity when tackling such a problem.
  vector<int> dailyTemperature(vector<int> &temperatures) {
    int size = temperatures.size();
    stack<int> st;
    vector<int> res(size, 0);
    // init
    st.push(temperatures[size - 1]);
    for (int i = size - 2; i >= 0; i--) {
      if (temperatures[i] < st.top()) {
        res[i]++;
        st.push(temperatures[i]);
      } else {
        stack<int> sttmp = st;
        res[i]++;
        // end loop until temperatures[i] < sttmp.top
        while (temperatures[i] >= sttmp.top()) {
          sttmp.pop();
          res[i]++;
          // not found; reset.
          if (sttmp.empty()) {
            res[i] = 0;
            break;
          }
        }
        st.push(temperatures[i]);
      }
    }
    return res;
  }
};

int main() {
  vector<int> input = {73, 74, 75, 71, 69, 72, 76, 73};
  Solution sol;
  vector<int> res = sol.dailyTemperature(input);
  printVector(res);
  return 0;
}
