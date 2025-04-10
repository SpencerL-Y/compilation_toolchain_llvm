#include "aliascheck.h"

int main(){

    int **p,*q;
    int *a,*b,c,d;
    p = &a;
    if(p){
        if(c){
            q = &c;
        }
    }
    else{
        p = &b;
        q = &d;
    }
    if(d){
        *p = q;
    }
------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4


}
