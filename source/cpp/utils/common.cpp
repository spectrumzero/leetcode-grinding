#include "utils/common.h"
void printVector(vector<int> &vec) {
  cout << "[";
  for (int i = 0; i < vec.size() - 1; i++) {
    cout << vec[i] << ",";
  }
  cout << vec[vec.size() - 1] << "]" << endl;
}
