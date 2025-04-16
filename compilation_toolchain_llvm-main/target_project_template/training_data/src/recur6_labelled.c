#include "aliascheck.h"
int *x,y,z;

void f();

int main(){
    f();
    *x=100;
}

void f(){
    
    if(z){
	x=&y;
	f();
	x=&z;
	f();
------- LABEL 1
------- LABEL 2
    }
------- LABEL 3
------- LABEL 4
}
