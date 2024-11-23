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
  bool isValidBST2(TreeNode *root) {
    stack<TreeNode *> stk;
    // Explicit Type Conversion
    long long inorder = (long long)INT_MIN - 1;
    TreeNode *current = root;

    // NOTE: Use a stack to store all nodes to be processed. Its FILO character ensures the correct order for in-order traversal.
    while (!stk.empty() || current != nullptr) {
      while (current != nullptr) {
        stk.push(current);
        current = current->left;
      }
      current = stk.top();
      stk.pop();
      // Implicit Conversion
      if (current->val <= inorder) {
        return false;
      }
      inorder = current->val;
      current = current->right;
    }
    return true;
  }
};

int main() {

  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(7);
  printTree(root);
  Solution sol;
  cout << sol.isValidBST2(root) << endl; // false!

  return 0;
}
