#include "aliascheck.h"
void foo(int*);
int ss = 20;
int main(){
    int *a,*b,obj,t;
    a=&obj;
    foo(a);
    *a=200;
    b=&t;
    foo(b);
------- LABEL 1
------- LABEL 2
}

void foo(int* x){
     static int* k =&ss;
    printf("%d\n", *k);
    *k=200;
    k=x;
     *x= 100;
}
