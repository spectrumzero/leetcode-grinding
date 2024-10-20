/* 0876: Middle of the Linked List */
#include "utils/common.h"

class Solution {
public:
  // using Array:
  // O(n)
  ListNode *middleNode(ListNode *head) {
    vector<ListNode *> vec;
    ListNode *cur = head;
    while (cur) {
      vec.push_back(cur);
      cur = cur->next;
    }

    int length = vec.size();
    return vec[length / 2];
  }

  // Single Pointer
  // O(n)
  ListNode *middleNodeSinglePtr(ListNode *head) {
    int n = 0;
    ListNode *cur = head;
    while (cur) {
      n++;
      cur = cur->next;
    }

    int k = 0;
    cur = head;
    while (k < n / 2) {
      k++;
      cur = cur->next;
    }

    return cur;
  }

  // Two Pointers (fast and slow)
  // O(n)
  ListNode *middleNodeTwoPtr(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }
};

int main() {

  ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))); // 4

  Solution sol;

  cout << sol.middleNode(head)->val << endl;

  return 0;
}
