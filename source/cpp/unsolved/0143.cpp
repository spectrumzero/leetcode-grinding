/* 0143: Reorder List */
#include "utils/common.h"

class Solution {
public:
  // Using Arrays
  // O(n)
  void reorderList(ListNode *head) {
    if (head == nullptr)
      return;
    vector<ListNode *> vec;
    ListNode *cur = head;
    while (cur) {
      vec.push_back(cur);
      cur = cur->next;
    }

    int i = 0, j = vec.size() - 1;
    while (i < j) {
      vec[i]->next = vec[j];
      i++;
      if (i == j)
        break;
      vec[j]->next = vec[i];
      j--;
    }

    vec[i]->next = nullptr;
  }

  // TODO: Method two
};

int main() {

  ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  Solution sol;
  printLinkedList(head); // 1->2->3->4->5->nullptr

  sol.reorderList(head);

  printLinkedList(head); // 1->5->2->4->3->nullptr

  return 0;
}
