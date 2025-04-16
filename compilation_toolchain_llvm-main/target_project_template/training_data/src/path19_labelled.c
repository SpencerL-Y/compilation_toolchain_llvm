#include "aliascheck.h"
int y,*q,*r,*f,*e,c,d;

void foo(int **p){

    if(y){
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
	int **a,**b;
    e = 0;
	a = &q; f = &d;	
	foo(a);
    b = &r; f = &c;
    foo(b);
------- LABEL 6
------- LABEL 7
------- LABEL 8
------- LABEL 9
}

