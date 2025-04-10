#include "aliascheck.h"

void foo(int**,int* );
int main(){

    int **p,*q;
    int *a,*b,c,d;
    if(a){
        p = &a;
        q = &c;
        foo(p,q);
    }
    else{
        p = &b;
        q = &d;
        foo(p,q);
    }

    *p = q;
------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4
}

void foo(int**x,int *y){
    *x = y;
}

