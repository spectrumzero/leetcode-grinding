/* 0739: Daily Temperatures */
#include "utils/common.h"

class Solution {
public:
  // O(n*n)
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

  // O(n)
  // Monotonic (Decreasing) Stack
  // Ensure the temperatures (not elements) corresponding to the indices (real elements) from the bottom to the top are in monotonically decreasing order.
  vector<int> dailyTemperaturegood(vector<int> &temperatures) {
    // NOTICE: the elements in the stack are indices of the vector `temperatures`, not values. the index is better because it contains the order information, with which you can compute the number of days between today and a warmer day.
    int size = temperatures.size();
    stack<int> st;
    vector<int> res(size, 0);
    for (int i = 0; i < size; i++) {
      // if the temperature of the new index is larger than that of top, then it is a warmer day. So we can get at least one result of previous days.
      while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
        // calculate the current result; the difference between the indices is equal to the number of days. Dont forget the element of stack is an index.
        res[st.top()] = i - st.top();
        // update the top by poping to get more results
        st.pop();
      }
      // but if it is less than or equal to top, we still can not figure out any result.
      // whatever the situation is, the new temperature itself should be added to the stack like a "waiting list" because it is the terminal day now.
      st.push(i);
    }
    return res;
  }
  // NOTE:
  // Q: WHY O(n) even though there is a while loop nested in the for loop?
  // A: Taking a closer look at the whole algorithm, we can find each element is pushed onto or popped from the stack exactly (no more than) once.
  //    The while loop here is used for poping the elements. No matter how random the temperatures order is or how many elements there are, the total times of pops are proportional to N.
  //    Even though the while loop inside the for loop might perform multiple pops in a single iteration, this does not mean that the total number of pops exceeds the total number of elements.
  //    More specifically, the more pops in a single iteration, the higher the likelihood that the next iteration will not occur, which means there will be no pops at all.
  //    All in all, the total number of pops across all iterations is equal to the total number of pushes, which is n, the number of elements.
};

int main() {
  vector<int> input = {31, 23, 33, 66, 21, 34, 33}; //[2,1,1,0,1,0,0]
  Solution sol;
  vector<int> res = sol.dailyTemperaturegood(input);
  printVector(res);
  return 0;
}
