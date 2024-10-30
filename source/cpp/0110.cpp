/* 0110: Balanced Binary Tree */
#include "utils/common.h"

class Solution {
public:
  // Binary Tree (post-order); Recursion; Record
  // O(n)
  int ans;

  bool isBalanced(TreeNode *root) {
    ans = 0;
    depth(root);
    return ans < 2;
  }

  int depth(TreeNode *root) {
    if (root == nullptr)
      return 0;
    int left = depth(root->left);
    int right = depth(root->right);
    int diff = abs(left - right);
    ans = max(ans, diff);
    return max(left, right) + 1;
  }
};

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  printTree(root);
  Solution sol;
  cout << sol.isBalanced(root) << endl; // 1

  return 0;
}
