/* 0230: Kth Smallest Element in a BST*/
#include "utils/common.h"

class Solution {

public:
  // Binary Tree; Recursion
  // O(n)
  vector<int> ans;

  int kthSmallest(TreeNode *root, int k) {
    dfs(root);
    return ans[k - 1];
  }

  void dfs(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    dfs(root->left);
    ans.push_back(root->val);
    dfs(root->right);
  }

  // Stack; Iteration
  // O(n)
  int kthSmallest2(TreeNode *root, int k) {
    stack<TreeNode *> stk;
    TreeNode *cur = root;
    int count = 0;
    while (!stk.empty() || cur) {
      while (cur) {
        stk.push(cur);
        cur = cur->left;
      }
      cur = stk.top();
      stk.pop();
      count++;
      if (count == k) {
        return cur->val;
      }
      cur = cur->right;
    }

    return INT_MIN;
  }
};

int main() {

  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->right = new TreeNode(4);
  root->left->right = new TreeNode(2);
  printTree(root);
  Solution sol;

  cout << sol.kthSmallest(root, 2) << endl;

  return 0;
}
