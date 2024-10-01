/* 0074: Search a 2D Matrix */

#include "utils/common.h"
#include <vector>

class Solution {
public:
  // O(log(m*n))
  // Two Binary Searches
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int rowTop = 0;
    int rowBot = matrix.size() - 1;
    int col = matrix[0].size() - 1;
    while (rowTop <= rowBot) {
      int rowMid = (rowTop + rowBot) / 2;
      if (target >= matrix[rowMid][0] && target <= matrix[rowMid][col]) {
        break;
      } else if (target < matrix[rowMid][0]) {
        rowBot = rowMid - 1;
      } else {
        rowTop = rowMid + 1;
      }
    }
    int rowFound = (rowTop + rowBot) / 2;

    int left = 0, right = col;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (target == matrix[rowFound][mid]) {
        return true;
      } else if (target > matrix[rowFound][mid]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return false;
  }

  // One Binary Search
  bool searchMatrixOne(vector<vector<int>> &matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();
    int left = 0;
    int right = row * col - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      // WARNING: A PATTERN
      int rowConvert = (mid / col);
      int colConvert = (mid % col);
      if (target == matrix[rowConvert][colConvert]) {
        return true;
      } else if (target > matrix[rowConvert][colConvert]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return false;
  }
};

int main() {
  std::vector<std::vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  Solution sol;
  cout << sol.searchMatrix(matrix, 8) << endl; // 1
  return 0;
}
