/* 1448: Count Good Nodes in Binary Tree */
#include "utils/common.h"

class Solution {
public:
  // Binary Tree; Recursion; path_max; INT_MIN
  // O(n)
  int goodNodes(TreeNode *root) { return dfs(root, INT_MIN); }

  int dfs(TreeNode *root, int path_max) {
    if (root == nullptr) {
      return 0;
    }

    int res = 0;
    if (root->val >= path_max) {
      res++;
      path_max = root->val;
    }
    res += dfs(root->left, path_max) + dfs(root->right, path_max);

    return res;
  }

  // More readable:
  int ans = 0;

  int goodNodes2(TreeNode *root) {
    dfs2(root, INT_MIN);
    return ans;
  }

  void dfs2(TreeNode *root, int path_max) {
    if (root == nullptr) {
      return;
    }

    if (root->val >= path_max) {
      ans++;
      path_max = root->val;
    }

    dfs2(root->left, path_max);
    dfs2(root->right, path_max);
  }
};

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->right = new TreeNode(4);
  root->left->left = new TreeNode(3);
  root->right->left = new TreeNode(1);
  root->right->right = new TreeNode(5);
  printTree(root);

  Solution sol;
  cout << sol.goodNodes(root) << endl; // 4

  return 0;
}
