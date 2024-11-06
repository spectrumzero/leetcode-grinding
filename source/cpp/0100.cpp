/* 0100: Same Tree */
#include "utils/common.h"

class Solution {
public:
  // `ugly` and `plain` method
  // O(n)
  int count = 1;
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr || q == nullptr)
      return p == q;

    int hcount = p->val == q->val ? 1 : 0;
    int lcount = isSameTree(p->left, q->left);
    int rcount = isSameTree(p->right, q->right);

    if (hcount == 0 || lcount == 0 || rcount == 0)
      count = 0;

    return count;
  }

  // more legible and elegant:
  bool isSameTreeEle(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) {
      return true;
    } else if (p == nullptr || q == nullptr) {
      return false;
    } else if (p->val != q->val) {
      return false;
    } else {
      return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
  }
};

int main() {
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(3);

  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->right = new TreeNode(3);

  Solution sol;
  cout << sol.isSameTreeEle(root1, root2) << endl; // 1
  return 0;
}
