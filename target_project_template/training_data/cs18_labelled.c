#include "aliascheck.h"
int obj,b;
void bar(int **s){
    *s = &b;
}

void foo(int **p){
	*p = &obj;
	bar(p);
}
main(){
	int **x;
	int *a, *c;
	x=&a; 
	foo(x);
------- LABEL 1
------- LABEL 2
	x = &c;
	foo(x);
------- LABEL 3
------- LABEL 4
	
}

