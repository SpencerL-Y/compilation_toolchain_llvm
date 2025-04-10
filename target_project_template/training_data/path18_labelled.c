#include "aliascheck.h"
int x,y,*q,*f,*e,d;

void foo(int **p){
	f = &x;
	if(x){
		p = &e;
		f = &y;
	}

	*p = f;
------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4
------- LABEL 5
}



int main(){
	int **a,c;
	a = &q; f = &d;	
	foo(a);
}

