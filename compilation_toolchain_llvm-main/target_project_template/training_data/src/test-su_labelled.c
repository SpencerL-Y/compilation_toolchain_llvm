#include "aliascheck.h"
int **p,**q;
int *x,*y,*z;
int a,b,c;
int main() {
	x=&a;
	y=&b;
	x=&b;
	x=&a;
	z=&b;
------- LABEL 1
------- LABEL 2
	return 0;
}
