/* 0572: Subtree of Another Tree */
#include "utils/common.h"

class Solution {
public:
  // `Violent` Recurion
  // O(n*n)
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (root == nullptr) {
      return false;
    }
    return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }

  bool isSameTree(TreeNode *t1, TreeNode *t2) {
    if (t1 == nullptr && t2 == nullptr) {
      return true;
    } else if (t1 == nullptr || t2 == nullptr) {
      return false;
    } else if (t1->val != t2->val) {
      return false;
    } else {
      return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
    }
  }

  // TODO: KMP

  // TODO: Tree Hash
};

int main() {
  TreeNode *tree = new TreeNode(1);
  tree->left = new TreeNode(2);
  tree->right = new TreeNode(3);
  tree->right->right = new TreeNode(5);

  TreeNode *subtree = new TreeNode(5);

  Solution sol;
  cout << sol.isSubtree(tree, subtree) << endl; // 1
  return 0;
}
