/* 0125: Valid Palindrome */
#include "utils/common.h"

class Solution {
public:
  /* O(n) */
  // two pointers
  bool isPalindrome(string s) {
    // convert the string into an alphanumeric string
    vector<char> neos;
    for (auto x : s) {
      if (isalnum(x)) {
        char tmp = tolower(x);
        neos.push_back(tmp);
      }
    }
    // use two pointers to traverse the neos from the start and end respectively;
    int n = neos.size();
    // start
    int left = 0;
    // end
    int right = n - 1;
    while (left < right) {
      if (neos[left] != neos[right])
        return false;
      left++;
      right--;
    }
    return true;
  }
};

int main() {
  string s = "N1bannab1N"; // true
  Solution sol;
  cout << sol.isPalindrome(s) << endl;
}

/* std::isalnum(int ch):
 * checks if the given charecter is an alphanumeric charecter.
 * By default, the digits(0123456789), uppercase letters(A-Z) and lowercase letters(a-z) are alphanumeric.
 *
 * std::tolower(int ch):
 * converts the given uppercase letter to the corresponding lowercase letter.
 * if any other unsigned char is passed, this function will not modify it.
 */
