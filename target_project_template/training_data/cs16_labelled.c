#include "aliascheck.h"
int *alloc( int size){

	return malloc(1);

}

void foo(int **p){

	*p = alloc(1);
	//*p = alloc();

}

void main(){

	int *a,*b,*c;
	foo(&a);
	foo(&b);
	foo(&c);
------- LABEL 1
------- LABEL 2
------- LABEL 3

}
