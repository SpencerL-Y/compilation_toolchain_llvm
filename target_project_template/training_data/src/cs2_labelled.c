#include "aliascheck.h"
int obj;
void foo(int **p, int **q, int **r){


	*r = *p;
	*q = &obj;

}


void main(){

	int **a,**b,**c,**d,**e,**f,*x,*y,*z,*w,*k,x1,y1,z1,w1,k1;
	x = &x1;
	y = &y1;
	z = &z1;
	w = &w1;
	k = &k1;

	a = &x;
	b = &y;
	c = &z;
	if(a){

		d = &w;
		e = &w;
		f = &k;
	}
	foo(a,b,c);
------- LABEL 1
------- LABEL 2
	foo(d,e,f);
------- LABEL 3
------- LABEL 4
------- LABEL 5
------- LABEL 6
------- LABEL 7

}
