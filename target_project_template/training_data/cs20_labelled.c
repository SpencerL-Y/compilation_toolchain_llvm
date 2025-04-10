#include "aliascheck.h"
int *obj;
int **x,*b,*w,d;
int **z, *a,*y,c;
void Zulu(int**p, int *q);
 
void Xray(){
	x = &b;
	w = &d;
	Zulu(x,w);
------- LABEL 1
------- LABEL 2
}

void Yank(){
	z = &a;
	y = &c;
	Zulu(z,y);
------- LABEL 3
------- LABEL 4
}

void Zulu(int**p,int *q){
	*q = 100;
	*p = q;

}

void main(){

	Xray();
	Yank();

}
