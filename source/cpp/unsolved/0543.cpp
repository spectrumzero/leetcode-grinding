/* 0543: Diameter of Binary Tree */
#include "utils/common.h"

class Solution {
public:
  // Binary Tree; Recursion; Record
  int ans;

  int diameterOfBinaryTree(TreeNode *root) {
    ans = 0;
    Depth(root);
    return ans;
  }

  int Depth(TreeNode *root) {
    if (root == nullptr)
      return 0;
    int L = Depth(root->left);
    int R = Depth(root->right);

    ans = max(ans, L + R);

    return max(L, R) + 1;
  }
};

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  printTree(root);

  Solution sol;
  cout << "the diameter of this tree is: " << sol.diameterOfBinaryTree(root) << endl;
}
