/* 0242: Valid Anagram */
#include "../utils/common.h"

class Solution {
public:
  /* O(n) */
  // hashtable(using array)
  bool isAnagramhashtablearray(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }
    // creates a std::vector of integers with 26 elements, all initialized to 0, which means the frequency.
    // Index from 0 to 25 references the character in the alphabet.
    vector<int> table(26, 0);
    for (auto &ch : s) {
      // update the frequency of each letter in the string.
      table[ch - 'a']++;
    }
    for (auto &ch : t) {
      table[ch - 'a']--;
      if (table[ch - 'a'] < 0) {
        // 1, the frequency of a letter in t is larger than that in s;
        // 2, the frequency of a letter in t is smaller thant in s, but because their string lengths are equal to each other, there must be an element which only exists in t.
        // Since this new element was not incremented, it remains 0. After being decremented, it is smaller than 0.
        return false;
      }
    }
    // The frequency of each letter in t is equal to that in s, So t is the Anagram of s.
    return true;
  }

  /* O(n) */
  // hashtable
  bool isAnagramhashtable(string s, string t) {
    // Notice: the map will automatically initialize the value to the default value for the value type. In this case the default value for int is 0.
    unordered_map<char, int> countmap;
    for (auto x : s) {
      countmap[x]++;
    }
    for (auto x : t) {
      countmap[x]--;
    }
    for (auto x : countmap) {
      // first: key part; second: value part
      if (x.second != 0) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  string s = "ohellcpp";
  string t = "hellocpp"; // true
  Solution sol;
  cout << sol.isAnagramhashtablearray(s, t) << endl;
  cout << sol.isAnagramhashtable(s, t) << endl;
}
