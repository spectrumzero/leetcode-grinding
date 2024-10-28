/* 0026: Invert Binary Tree */
#include "utils/common.h"

class Solution {
public:
  // Binary Tree; Recursion
  // O(n)
  TreeNode *invertTree(TreeNode *root) {
    if (!root)
      return nullptr;
    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
  }
};

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  printTree(root);

  Solution sol;
  sol.invertTree(root);

  printTree(root);

  return 0;
}
