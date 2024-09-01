/* 1002: Find Common Characters*/
#include "../utils/common.h"

class Solution {
public:
  /* O(n*m); m is the average length of the strings in the input list. */
  // hashtable
  vector<string> commonChars(vector<string> &words) {
    int n = words.size();
    // alphabet of frequency
    vector<int> hashMap(26, 0);
    // deduce type automatically and avoid copy construction
    for (auto &k : words[0]) {
      // stores the final result of the frequency. It will be updated through the next loop.
      hashMap[k - 'a']++;
    }
    // update the hashMap starting from the second string
    for (int i = 1; i < n; i++) {
      vector<int> hashMaptmp(26, 0);
      for (auto &k : words[i]) {
        // Stores the frequency in the current string
        hashMaptmp[k - 'a']++;
      }
      // Compare current frequency with last updated frequency. Update hashmap to ensure hashmap stores the minimum frequency of the letter in the words.
      for (int j = 0; j < 26; j++) {
        hashMap[j] = min(hashMap[j], hashMaptmp[j]);
      }
      // next string
    }
    // output
    vector<string> result;
    for (int i = 0; i < 26; i++) {
      // the condition expression in the while loop serves two purposes:
      // first is to check whether hashmap[i]>0; the value will be returned before it is decremented;
      // second is to decrement the hashmap[i] because a letter may occur equal multiple times in each string like the example below.
      while (hashMap[i]--) {
        // std::vector::push_back: Add new value at the end of the vector;
        // std::vector::string(n,char): Create a string by repeating a character n times. "i+'a'" will be transformed to ASCII first and then be turned into a character;
        // And that is why we always limit the range of i to [0,25].
        result.push_back(string(1, i + 'a'));
      }
    }
    return result;
  }
};

int main() {
  vector<string> input = {"datastructure", "dsaa", "doaalgorithms", "aasspd"}; // [a,a,d,s]
  Solution s1;
  vector<string> res;
  res = s1.commonChars(input);
  cout << "[ ";
  for (int i = 0; i < res.size() - 1; i++) {
    cout << res[i] << ",";
  }
  cout << res[res.size() - 1] << " ]" << endl;
}
