/* 0104: Maximum Depth of Binary Tree */
#include "utils/common.h"

class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr)
      return 0;
    int lheight = maxDepth(root->left);
    int rheight = maxDepth(root->right);
    return max(lheight, rheight) + 1;
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
  cout << "the max depth of this tree is: " << sol.maxDepth(root) << endl;

  return 0;
}
