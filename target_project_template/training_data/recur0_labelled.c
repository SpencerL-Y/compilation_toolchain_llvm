#include "aliascheck.h"
int *x, y, z;

void f() {
  if(z > 5) return;
  z++;
  if (1) {
         x = &y;
------- LABEL 1
          f();
         x = &z;
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
