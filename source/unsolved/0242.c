/* 0242: valid anagram */

#include "../../utils/common.h"

/* the comparation function for comparing two character. this function sets the sorting rules for the qsort.*/
int compar(const void *_a, const void *_b) {
  // type conversion
  char a = *(char *)_a;
  char b = *(char *)_b;
  return a - b;
}

bool isAnagram(char *_s, char *_t) {
  int len_s = strlen(_s); // 8
  int len_t = strlen(_t); // 8
  // improve the efficiency of algorithm.
  if (len_s != len_t)
    return false;

  // void qsort( void* ptr, size_t count, size_t size,int (*comp)(const void*, const void*) );
  qsort(_s, len_s, sizeof(char), compar);
  qsort(_t, len_t, sizeof(char), compar);

  // use strcmp to compare two null-terminated strings lexicographcally
  // int strcmp( const char* lhs, const char* rhs )
  return strcmp(_s, _t) == 0;
}

int main() {
  char s[] = "babyface";
  char t[] = "bayfaecb";
  printf("%d", isAnagram(s, t));
  return 0;
}

/*
parameters in void qsort:
ptr -> pointer to the array to sort;
count -> number of elements in the array;
size -> size of each element in the array in bytes;
comp -> comparison function which returns a negative integer value if the first argument is less
than the second, a positive integer value if the first argument is greater than the second and 0
if the arguments are equivalent.
*/

/*
return values of strcmp:
Negative value if lhs appears before rhs in lexicographical order.
Zero if lhs and rhs compare equal.
Positive value if lhs appears after rhs in lexicographical order.
*/
