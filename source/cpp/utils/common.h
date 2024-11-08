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
#include <utility>
#include <vector>
using namespace std;

// ListNode struct
typedef struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;

// TreeNode struct
typedef struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
} TreeNode;

// trunk for printer
struct Trunk {
  Trunk *prev;
  string str;
  Trunk(Trunk *prev, string str) {
    this->prev = prev;
    this->str = str;
  }
};

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

// print binary tree
void showTrunks(Trunk *p);
void printTree(TreeNode *root, Trunk *prev, bool isRight);
void printTree(TreeNode *root);

#endif // !COMMON_H
