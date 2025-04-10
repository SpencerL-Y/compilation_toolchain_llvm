#include "aliascheck.h"
void f(int** a, int *b)
{
 *a = b; 
}

typedef void (*fp)(int**,int*);

void main()
{
        int **x,*y,*z;
        int *m,*n,m1,n1;
        m = &m1;
        n = &n1;
	fp p = &f;
	x = &y;
	(*p)(x,m);       /* these are equivalent */
------- LABEL 1
------- LABEL 2
	x = &z;
	p(x,n);
------- LABEL 3
------- LABEL 4
}

