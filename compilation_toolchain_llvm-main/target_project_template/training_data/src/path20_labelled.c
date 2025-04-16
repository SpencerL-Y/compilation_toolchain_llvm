#include "aliascheck.h"
int main(){

    int**a,**b, *f,*g,r,w,q,*obj,k;
    f = &k;
    if(a){
        a = &f;
        f = &r;
    }
    else{
        a = &g;
        g = &w;
    }
    a = b;

    *a = &q;
    obj = *b;
------- LABEL 1
------- LABEL 2
------- LABEL 3

}
