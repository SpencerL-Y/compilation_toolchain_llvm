#include "aliascheck.h"
int obj, t,s;
int *k =&s;
void foo(int**, int**);
main(){
	int **x, **y;
	int *a, *b, *c, *d,*e;
    a = &t;
	x=&a; y =&b; 
	foo(x,y);
------- LABEL 1
------- LABEL 2
	*b = 5;
	c=&t;
	c=&s;
	a=c;
------- LABEL 3
	if(t) {c=&obj; x =&c; y =&e;}
	else { x= &d; y = &d;}
	e = &t;
	foo(x,y);
------- LABEL 4
------- LABEL 5
------- LABEL 6
------- LABEL 7
------- LABEL 8
	*e = 10;
	
}

void foo(int **p, int **q){
	*p = *q;
	*q = &obj;
}
