#include "aliascheck.h"
int main(){
    int ***m,**n,*z,*y,z1,y1;

    m=&n;
    n=&z;
    *m=&y;
------- LABEL 1
------- LABEL 2
    z=&z1;
    y=&y1;
    ***m=10;
    z=**m;
------- LABEL 3
}
