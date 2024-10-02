/* 0875: Koko Eating Bananas */

#include "utils/common.h"

class Solution {
public:
  // Binary Search
  // O(nlogm)
  int minEatingSpeed(vector<int> &piles, int h) {
    int low = 1, high = 0;
    // NOTE: a constraint: h >= piles.size()
    for (auto pile : piles) {
      high = max(high, pile);
    }

    while (low < high) {
      int speed = low + (high - low) / 2;
      int time = getTime(piles, speed);
      if (time <= h) {
        high = speed;
      } else {
        low = speed + 1;
      }
    }

    return high;
  }

  int getTime(vector<int> &piles, int speed) {
    int time = 0;
    for (auto pile : piles) {
      // NOTE: ceiling()
      time += (pile + speed - 1) / speed;
    }
    return time;
  }
};

int main() {
  vector<int> piles = {30, 11, 23, 4, 20};
  Solution sol;
  cout << sol.minEatingSpeed(piles, 8) << endl; // 15*2 + 15*1 + 15*2 + 15*1+ 15*2 = 15*(2+1+2+1+2) = 15(speed) *8(hour)

  return 0;
}
