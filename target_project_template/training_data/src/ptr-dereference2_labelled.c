#include "aliascheck.h"

int main(){

  int **a, *b, *x ,c;
  c = 10;
  a = &b;
  b = &c;
  x = *a;
  int y = *x;
------- LABEL 1
------- LABEL 2
  return 0;
}
