#include "utils/common.h"

void printLinkedList(ListNode *head) {
  ListNode *cur = head;
  while (cur) {
    cout << cur->val << "->";
    cur = cur->next;
  }
  cout << "nullptr" << endl;
}

/**
 * https://www.techiedelight.com/c-program-print-binary-tree/
 */
// starts
void showTrunks(Trunk *p) {
  if (p == nullptr) {
    return;
  }
  showTrunks(p->prev);
  cout << p->str;
}

void printTree(TreeNode *root, Trunk *prev, bool isRight) {
  if (root == nullptr) {
    return;
  }

  string prev_str = "    ";
  Trunk trunk(prev, prev_str);

  printTree(root->right, &trunk, true);

  if (!prev) {
    trunk.str = "———";
  } else if (isRight) {
    trunk.str = "/———";
    prev_str = "   |";
  } else {
    trunk.str = "\\———";
    prev->str = prev_str;
  }

  showTrunks(&trunk);
  cout << " " << root->val << endl;

  if (prev) {
    prev->str = prev_str;
  }
  trunk.str = "   |";

  printTree(root->left, &trunk, false);
}

void printTree(TreeNode *root) {
  printTree(root, nullptr, false);
  cout << "+++++++++++++++++++++++++++++++++++" << endl;
}
// ends
