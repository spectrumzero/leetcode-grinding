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

  // FindMiddleNode(876), Reverse(206), Merge.
  // O(n)
  void reorderListMethodTwo(ListNode *head) {
    if (head == nullptr)
      return;

    ListNode *mid = getMid(head);
    ListNode *l1 = head;
    ListNode *l2 = mid->next;
    mid->next = nullptr;
    l2 = reverseList(l2);

    mergeLists(l1, l2);
  }

  ListNode *getMid(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }

  ListNode *reverseList(ListNode *head) {
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur) {
      ListNode *next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }

    return pre;
  }

  void mergeLists(ListNode *l1, ListNode *l2) {
    ListNode *l1_tmp;
    ListNode *l2_tmp;

    while (l1 && l2) {
      l1_tmp = l1->next;
      l2_tmp = l2->next;

      l1->next = l2;
      l1 = l1_tmp;

      l2->next = l1;
      l2 = l2_tmp;
    }
  }
};

int main() {

  ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  Solution sol;
  printLinkedList(head); // 1->2->3->4->5->nullptr

  sol.reorderListMethodTwo(head);

  printLinkedList(head); // 1->5->2->4->3->nullptr

  return 0;
}
