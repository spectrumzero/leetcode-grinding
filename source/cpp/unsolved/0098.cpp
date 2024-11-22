/* 0098: Validate Binart Search Tree */
#include "utils/common.h"

class Solution {
public:
  // Binary Search; Recursion; Tricks
  // O(n)
  bool isValidBST(TreeNode *root) { return dfs(root, LONG_MIN, LONG_MAX); }

  bool dfs(TreeNode *root, long long lower, long long upper) {
    if (root == nullptr) {
      return true;
    }

    if (root->val <= lower || root->val >= upper) {
      return false;
    }

    return dfs(root->left, lower, root->val) && dfs(root->right, root->val, upper);
  }

  // TODO:Stack
};

int main() {

  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(7);
  printTree(root);
  Solution sol;
  cout << sol.isValidBST(root) << endl; // false!

  return 0;
}
