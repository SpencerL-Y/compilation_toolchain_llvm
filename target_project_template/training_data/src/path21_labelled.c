#include "aliascheck.h"
int main(){
    int ***p,**a,**b,*q,*r,*f,v,z,*g,f1; 

    p = &a;
    a = b = &f;
    f = &f1;
    q = &v;

    if(a){
        f = &z;
        *p = &g;
        b = *p;
    }
    else{


    }

    *a = q;
    r = *b;
------- LABEL 1
------- LABEL 2
------- LABEL 3
}
