#include "aliascheck.h"
int main(){
    int **p,*q;
    int *a,*b,c,d,e;
    q = &c;
    if(a){
        p = &a;
        if(c){
            q = &d;
        }
    }
    else{
        p = &b;
        q = &e;
    }

    *p = q;
------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4
------- LABEL 5
------- LABEL 6

}
