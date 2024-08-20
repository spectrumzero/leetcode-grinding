/* 0217: Contains Duplicate */
#include "../utils/common.h"

class Solution {
public:
  /*O(n)*/
  bool containsDuplicate(vector<int> &nums) {
    unordered_set<int> s;
    for (int x : nums) {
      // The find() function checks if x already exists in the set s, which stores only unique keys.
      if (s.find(x) != s.end()) {
        return true;
      }
      // Add the element while ensuring the uniqueness of each member.
      s.insert(x);
    }
    return false;
  }
};

int main() {
  vector<int> nums = {1, 2, 4, 6, 7, 2}; // true
  Solution s;
  cout << s.containsDuplicate(nums) << endl;
}

/* std::unordered_set::find:
First it will hash the passed key to produce a hash value. Using this hash value, it then locates the corresponding bucket index.
After locating the bucket which contains elements using chaining, it searches the elements within that bucket with O(1) in average.
If the key is found, the function returns a iterator pointing to that element.
Otherwise, it returns end(), an iterator that represents the past-the-end position in the container.
*/
