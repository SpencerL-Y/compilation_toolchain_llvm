#include "aliascheck.h"

void foo(int**, int*);
main(){
	int **x, *y;
	int  *c, *d,e,f;
	if(x) { x =&c; y =&e;}
	else { x= &d; y = &f;}
	foo(x,y);
------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4
	
}

void foo(int **p, int *q){
	*p = q;
}
