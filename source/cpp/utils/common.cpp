#include "utils/common.h"

void printLinkedList(ListNode *head) {
  ListNode *cur = head;
  while (cur) {
    cout << cur->val << "->";
    cur = cur->next;
  }
  cout << "nullptr" << endl;
}
