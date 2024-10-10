#ifndef COMMON_H
#define COMMON_H

#include <algorithm>
#include <cctype>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// ListNode struct
typedef struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;

// print vector
template <typename T> void printVector(const vector<T> &vec) {
  cout << "[";
  for (size_t i = 0; i < vec.size() - 1; i++) {
    cout << vec[i] << ",";
  }
  cout << vec[vec.size() - 1] << "]" << endl;
}

// print LinkedList
void printLinkedList(ListNode *head);

#endif // !COMMON_H
