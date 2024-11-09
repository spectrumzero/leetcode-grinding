/* 0102: Binary Tree Level Order Traversal */
#include "utils/common.h"

class Solution {
public:
  // Binary Tree; Queue
  // O(n)
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (root == nullptr)
      return ans;

    // NOTE:A Pattern for BFS: Serialize binary tree into a queue
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      // initialization for every level
      vector<int> currentLevelContainer;
      int currentLevelSize = q.size();

      ans.push_back(currentLevelContainer);

      // add
      for (int i = 1; i <= currentLevelSize; i++) {
        TreeNode *node = q.front();
        q.pop();
        ans.back().push_back(node->val);
        // for next level
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
    }

    return ans;
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
  vector<vector<int>> ans = sol.levelOrder(root);
  print2DVector(ans);

  return 0;
}

// NOTE:
// 1. queue.empty(): true if empty
// 2. queue.size(): the number of elements
// 3. queue.front(): access the first element
// 4. queue.back(): access the last element
// 5. queue.push(): insert the element at the end
// 6. queue.pop(): remove the first element
// 7. vector.back(): access the last element
