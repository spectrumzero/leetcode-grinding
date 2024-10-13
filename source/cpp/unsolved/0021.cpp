/* 0021: Merge Two Sorted Lists */
#include "utils/common.h"

class Solution {
public:
  // Iteration
  // O(m+n)
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *preHead = new ListNode(-1);
    ListNode *prev = preHead;
    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val <= list2->val) {
        prev->next = list1;
        list1 = list1->next;
      } else {
        prev->next = list2;
        list2 = list2->next;
      }
      prev = prev->next;
    }

    prev->next = (list1 == nullptr ? list2 : list1);

    return preHead->next;
  }

  // TODO: Recursive
};

int main() {
  ListNode *list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
  ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
  Solution sol;
  ListNode *merge = sol.mergeTwoLists(list1, list2);
  printLinkedList(merge);
  return 0;
}
