/* 0973: K Closest Points to Origin */
#include "utils/common.h"

class Solution {
public:
  // maxheap; pair; topk
  // nlogn
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    priority_queue<pair<int, int>> q;
    // first closest k
    for (int i = 0; i < k; i++) {
      int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
      // NOTE:
      // The std::pair type comes with a default lexicographical comparison.
      q.emplace(dist, i);
    }
    // updates
    for (int i = k; i < points.size(); i++) {
      int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
      if (dist < q.top().first) {
        q.pop();
        q.emplace(dist, i);
      }
    }

    // extract and build
    vector<vector<int>> ans;
    while (!q.empty()) {
      int index = q.top().second;
      ans.push_back(points[index]);
      q.pop();
    }

    return ans;
  }
};

int main() {
  vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
  Solution sol;
  vector<vector<int>> ans = sol.kClosest(points, 2); // [[3,3],[-2,4]]
  print2DVector(ans);
}
