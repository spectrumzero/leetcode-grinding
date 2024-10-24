/* 0002: Add Two Numbers */
#include "utils/common.h"

class Solution {
public:
  // Math
  // O(n)
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(0);
    ListNode *cur = dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
      int n1 = l1 ? l1->val : 0;
      int n2 = l2 ? l2->val : 0;
      int sum = n1 + n2 + carry;
      carry = sum >= 10 ? 1 : 0;
      cur->next = new ListNode(sum % 10);
      cur = cur->next;
      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
    }

    return dummy->next;
  }
};

int main() {
  ListNode *l1 = new ListNode(6, new ListNode(5, new ListNode(9))); // number: 956; linkedlist: 6->5->9
  ListNode *l2 = new ListNode(3, new ListNode(1, new ListNode(2))); // number: 213; linkedlist: 3->1->2
  Solution sol;
  ListNode *ans = sol.addTwoNumbers(l1, l2);
  printLinkedList(ans); // sum: 1169; linkedlist: 9->6->1->1

  return 0;
}
