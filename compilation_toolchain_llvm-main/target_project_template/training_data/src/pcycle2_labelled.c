#include "aliascheck.h"
int main(){

    int **a,**b,**c;
    int k;
    a=&b;
    *a=&c;
    *b=&a;
------- LABEL 1
------- LABEL 2
------- LABEL 3
    
}
