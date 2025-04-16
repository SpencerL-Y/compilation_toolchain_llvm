#include "aliascheck.h"
int **p,*x, y, z;

void f() {
  p = &x;
  if (z) {
    *p = &y;
------- LABEL 1
    f();
    *p = &z;
------- LABEL 2
------- LABEL 3
    f();
  }
}


int main()
{
    f();
    return 0;
}
