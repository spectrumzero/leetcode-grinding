/* 0199: Binary Tree Right Side View */
#include "utils/common.h"
#include <vector>

class Solution {
public:
  // DFS (root->right->left);
  // O(n)
  vector<int> res;

  vector<int> rightSideViewDfs(TreeNode *root) {
    dfs(root, 0);
    return res;
  }

  void dfs(TreeNode *root, int depth) {
    if (root == nullptr)
      return;

    // NOTE:
    if (depth == res.size()) {
      res.push_back(root->val);
    }

    dfs(root->right, depth + 1);
    dfs(root->left, depth + 1);
  }

  // BFS;
  // O(n)
  vector<int> rightSideView(TreeNode *root) {
    vector<int> ans;
    if (root == nullptr) {
      return ans;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      ans.push_back(q.back()->val);

      int cursize = q.size();
      for (int i = 1; i <= cursize; i++) {
        TreeNode *node = q.front();
        q.pop();
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
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(4);
  printTree(root);

  Solution sol;
  vector<int> vec = sol.rightSideView(root); // [1,3,4]
  printVector(vec);

  return 0;
}
