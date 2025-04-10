#include "aliascheck.h"
int* x, x1;
void f(int **m){
int **n,*y,*k,z,r;
   n = &y;
   y = &z;
   if(z==1){
	*n=&r;
------- LABEL 1
------- LABEL 2
	k = *n;
------- LABEL 3
------- LABEL 4
	f(n);
   }
}

int main(){
	x=&x1;
	f(x);
}
