#include "aliascheck.h"

int main(){
    int **p, *q, **w,*v, *a,a1,q1;
    a = &a1;
    p = &a;
    q = &q1;
    w = 0;
    if(p)
        *p = q;
    else
        w = &a;

    v = *w;
------- LABEL 1
------- LABEL 2

}
