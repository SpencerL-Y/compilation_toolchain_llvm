#include "aliascheck.h"
int g;
int* obj = &g;
void Zulu(int**p, int *q);
 
void Xray(){

	int **x,*b,*w,d;
	x = &b;
	w = &d;
	Zulu(x,w);
------- LABEL 1
------- LABEL 2
}


void Zulu(int**p,int *q){

	*p = q;
    *p = obj;
}

void main(){

	Xray();

}
