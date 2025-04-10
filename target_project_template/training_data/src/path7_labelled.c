#include "aliascheck.h"

int main(){

    int **p,*q;
    int *b,*c,d,e;

    p = &c;
    q = &e;

    if(d){
        p = &b;
    }
    else{
        q = &d;
    }

    *p = q;

------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4
}
