#include "aliascheck.h"
int* x,y;
void f(int *m){
------- LABEL 1
	int *n;
	if(y==1){
		n=&y;

		f(n);
	}
}

int main(){
	x=&y;
	f(x);
}
