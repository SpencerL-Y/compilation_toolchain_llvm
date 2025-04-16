#include "aliascheck.h"
void foo(int **x,int**y,int **z, int *w){
	int *t;
	*y = w;
	t = *x;
	*z = t;

}

int main(){

	int *a,*b,*c,d,*p,*q,r,a1;
    a = &a1;
	foo(&a,&b,&c,&d);
------- LABEL 1
------- LABEL 2
	foo(&p,&p,&q,&r);
------- LABEL 3
------- LABEL 4
------- LABEL 5
------- LABEL 6
}
