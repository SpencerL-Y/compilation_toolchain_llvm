#include "aliascheck.h"

void foo(int** s);
void bar(int** s);
int k;
int main(){

    int **p,*q;
    int *b,*c,e;
    if(e){
        p = &b;
        foo(&q);
    }
    else{
        p = &c;
        q = &e;
    }

    *p = q;
------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4
}

void foo(int**x){
    bar(x);
}

void bar(int**s){
    *s = &k;
}
