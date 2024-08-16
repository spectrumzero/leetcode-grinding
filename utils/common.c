#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printarray(int *res, int ressize) {
  for (int i = 0; i < ressize - 1; i++) {
    printf("%d,", res[i]);
  }
  printf("%d ]\n", res[ressize - 1]);
}
