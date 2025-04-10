#include "aliascheck.h"
int a;
int *foo(int *x){
   int*z = x;
   int* y;
   if(x)
    y = foo(z);
   else
    y = x;

------- LABEL 1
    return y;

}

int main(){
 int*p;
 p = &a;

 foo(p);

}
