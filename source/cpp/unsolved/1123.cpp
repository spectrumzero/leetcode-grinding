/* 1123: Lowest Common Ancestor of Deepest Leaves */
#include "utils/common.h"

class Solution {
public:
  // Recursion; `pair`
  // O(n)
  pair<TreeNode *, int> dfs(TreeNode *root) {
    if (root == nullptr) {
      return {root, 0};
    }

    auto left = dfs(root->left);
    auto right = dfs(root->right);

    // first: lca; second: the depth of the current tree
    if (left.second > right.second) {
      return {left.first, left.second + 1};
    }
    if (left.second < right.second) {
      return {right.first, right.second + 1};
    }
    return {root, left.second + 1};
  }

  TreeNode *lcaDeepestLeaves(TreeNode *root) { return dfs(root).first; }
};

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->left->left = new TreeNode(6);
  root->left->left->right = new TreeNode(7);
  printTree(root);

  Solution sol;
  cout << sol.lcaDeepestLeaves(root)->val << endl; // 4

  return 0;
}
