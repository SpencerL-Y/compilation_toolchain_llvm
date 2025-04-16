#include "aliascheck.h"

int main(){

    int **p,*q;
    int *b,*c,d,e;

    p = &c;

c1:    if(e){
           p = &b;
           q = &d;
       }
       else if(b) {
           q = &e;
       }
       else if(c){
          printf("dummy branch\n");
       }
       else{
           goto c1;
       }

       *p = q;
------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4
------- LABEL 5
------- LABEL 6
}
