#include "aliascheck.h"
int x, *y, z;
void f(int **m);
void main(){

	int **a = &y;

	f(a);


}

void f(int **m){
	if(x){
		*m = &x;
------- LABEL 1
------- LABEL 2
		f(m);
	}
	else{
		*m = &z;
------- LABEL 3
------- LABEL 4
	}

}
