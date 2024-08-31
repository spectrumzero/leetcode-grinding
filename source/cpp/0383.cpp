/* 0383: Ransom Note */
#include "./utils/common.h"

class Solution {
public:
  /* O(n) */
  // hashtable
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> map;
    // initialization
    for (auto x : ransomNote) {
      map[x]++;
    }
    // updating
    for (auto x : magazine) {
      map[x]--;
    }
    // judgement
    for (auto x : map) {
      if (x.second > 0)
        return false;
    }
    return true;
  }

  /* O(n) */
  // hashtable (using array)
  bool canConstruct2(string ransomNote, string magazine) {
    // create a vector with the capacity of 26, each of the elements initialized with 0;
    vector<int> countmap(26, 0);
    for (auto x : ransomNote) {
      // Notice: Use single quote to represent char.
      countmap[x - 'a']++;
    }
    for (auto x : magazine) {
      countmap[x - 'a']--;
    }
    for (auto x : countmap) {
      if (x > 0)
        return false;
    }
    return true;
  }
};

int main() {
  string n = "hello";
  string m = "ollehfdajl"; // true
  Solution sol;
  cout << sol.canConstruct(n, m) << endl; // true
  cout << sol.canConstruct(m, n) << endl; // false
  return 0;
}
