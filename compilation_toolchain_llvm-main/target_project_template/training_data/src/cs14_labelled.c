#include "aliascheck.h"
void foo(int*,int*);
main(){
	int*x, *y;
	int a,b, c;
	if(c)x=&a; 
	else x=&b;
------- LABEL 1
------- LABEL 2
	foo(x,y);
	x = &c;
	foo(x,y);
------- LABEL 3
------- LABEL 4
------- LABEL 5
	
}

void foo(int *p,int*q){
	*p = 100;
}
