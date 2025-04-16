#include "aliascheck.h"
void foo(int q){
  int i = 10;
  int k = i;

}
int main(){

int *s,*r,*x,**y,t,z,k;
	s = &t;
	r = &z;
	y = &r;
	s = r;
------- LABEL 1
	x = *y;
------- LABEL 2
	foo(k);
return 0;
}
