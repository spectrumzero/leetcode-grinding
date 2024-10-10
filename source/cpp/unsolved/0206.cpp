/* 0206: Reverse Linked List */

#include "utils/common.h"

class Solution {
public:
  // LinkedList
  // O(n)
  ListNode *reverseList(ListNode *head) {
    ListNode *cur = head;
    ListNode *pre = nullptr;
    while (cur) {
      ListNode *next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    return pre;
  }

  // Recursive
  // O(n)
  ListNode *reverseListRecursive(ListNode *head) {
    // base case
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *newhead = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newhead;
  }
};

int main() {
  ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  Solution sol;
  printLinkedList(head); // 1->2->3->4->5->nullptr
  ListNode *newhead = sol.reverseListRecursive(head);
  printLinkedList(newhead); // 5->4->3->2->1->nullptr
  return 0;
}
