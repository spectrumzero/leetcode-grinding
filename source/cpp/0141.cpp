/* 0141: Linked List Cycle */
#include "utils/common.h"
#include <iostream>

class Solution {
public:
  // Linked List + Hash Table
  // O(n)
  bool hasCycle(ListNode *head) {
    unordered_set<ListNode *> set;
    ListNode *cur = head;
    while (cur) {
      if (set.count(cur->next))
        return true;
      set.insert(cur);
      cur = cur->next;
    }

    return false;
  }

  // More brief
  bool hasCycle2(ListNode *head) {
    unordered_set<ListNode *> seen;
    while (head) {
      if (seen.count(head)) {
        return true;
      }
      seen.insert(head);
      head = head->next;
    }
    return false;
  }

  // Two Pointers
  // O(n); O(1)
  bool hasCycle3(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return false;
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow != fast) {
      if (fast == nullptr || fast->next == nullptr)
        return false;
      slow = slow->next;
      fast = fast->next->next;
    }

    return true;
  }
};

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = head;

  Solution sol;
  cout << sol.hasCycle(head) << endl; // 1
}
