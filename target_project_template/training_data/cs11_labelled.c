#include "aliascheck.h"
void foo(int**a, int*b){

	*a = b;

}


void main(){

	int *p,q,*x,y;
	foo(&p,&q);
------- LABEL 1
	foo(&x,&y);
------- LABEL 2
------- LABEL 3
------- LABEL 4

	*p = 100;

}
