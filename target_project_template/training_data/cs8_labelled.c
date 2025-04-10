#include "aliascheck.h"
int obj1,obj2;
void foo(int **p, int **q){

	*p = &obj1;
	*q = &obj2;

}

int main(){

	int **a,**b,*x,*y,*z;
	if(a){
		a = &x;
		b = &y;
	}
	else{
		a = &z;
		b = &z;
	}
	foo(a,b);
------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4
------- LABEL 5

}
