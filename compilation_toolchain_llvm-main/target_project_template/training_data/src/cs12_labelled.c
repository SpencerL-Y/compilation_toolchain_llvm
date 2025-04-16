#include "aliascheck.h"
int obj;
void foo(int**, int**);
main(){
	int **x, **y;
	int *a, *b, *c, *d,*e;
	x=&a; y =&b; 
	foo(x,y);
------- LABEL 1
	x = &c;
	foo(x,y);
------- LABEL 2
	
}

void foo(int **p, int **q){
	*p = &obj;
}
