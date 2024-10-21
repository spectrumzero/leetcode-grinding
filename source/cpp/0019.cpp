/* 0019: Remove Nth Node From End of List */
#include "utils/common.h"
#include <stack>

class Solution {
public:
  // using Array
  // O(n)
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *cur = head;
    vector<ListNode *> vec;
    while (cur) {
      vec.push_back(cur);
      cur = cur->next;
    }

    int pos = vec.size() - n;

    if (pos == 0) {
      return vec[pos]->next;
    } else {
      ListNode *next = vec[pos]->next;
      ListNode *pre = vec[pos - 1];
      pre->next = next;
    }

    return head;
  }

  // Stack
  // O(n)
  ListNode *removeNthFromEndStk(ListNode *head, int n) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *cur = dummy;
    stack<ListNode *> stk;
    while (cur) {
      stk.push(cur);
      cur = cur->next;
    }

    for (int i = 0; i < n; i++) {
      stk.pop();
    }
    ListNode *pre = stk.top();
    pre->next = pre->next->next;

    ListNode *ans = dummy->next;
    return ans;
  }
};

int main() {
  ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  Solution sol;
  sol.removeNthFromEnd(head, 1); // 1->2->3->4
  printLinkedList(head);

  return 0;
}
