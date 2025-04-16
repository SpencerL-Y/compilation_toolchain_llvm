#include "aliascheck.h"
int main(){

    int **p,*q;
    int *a,*b,c,d;
    int *x;

    p = &a;
    if(p){
        if(c){
            q = &c;
        }
    }
    else{
        if(c)
            p = &b;
        q = &d;
    }
    if(p){
        *p = q;
    }

------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4


}
