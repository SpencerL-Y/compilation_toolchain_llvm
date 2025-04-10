/*
 * Alias with array
 * Author: Sen Ye
 * Date: 06/09/2013
 */
#include "aliascheck.h"

struct MyStruct {
	int * f1;
	int * f2;
};

int main() {
	struct MyStruct s[2];
	int a,b;
	s[0].f1 = &a;
	s[1].f1 = &b;

	// Different fields of different elements in a 
	// certain array are treated as different objects.
------- LABEL 1
------- LABEL 2

	return 0;
}
/*
 * Alias with array
 * Author: Sen Ye
 * Date: 06/09/2013
 */
#include "aliascheck.h"

struct MyStruct {
	int * f1;
	int * f2;
};

int main() {
	struct MyStruct s[2];
	int a,b;
	s[0].f1 = &a;
	s[1].f1 = &b;

	// Different fields of different elements in a 
	// certain array are treated as different objects.
------- LABEL 1

	return 0;
}
/*
 * Alias with array
 * Author: Sen Ye
 * Date: 06/09/2013
 */
#include "aliascheck.h"

struct MyStruct {
	int * f1;
	int * f2;
};

int main() {
	struct MyStruct s[2];
	int a,b;
	s[0].f1 = &a;
	s[1].f1 = &b;

	// Different fields of different elements in a 
	// certain array are treated as different objects.
------- LABEL 1
------- LABEL 2

	return 0;
}
------- LABEL 1
int main() {
	int a, b;
	int* source[2] = {&a, &b};
	int* x = source[1];
------- LABEL 2
	return 0;
}
/*
 * Array alias in flow-sensitive analysis.
 * Author: Sen Ye
 * Date: 08/11/2013
 */

#include "aliascheck.h"

struct MyStruct {
	int *f1;
	int *f2;
};

int main() {
	struct MyStruct s[2];
	int x, y;
	s[0].f1 = &x;
	s[1].f2 = &y;

	// Arrays are treated as a single element.
	// Different fields have its own points-to set.
	// Same fields have same points-to set, even they belong
	// to different elements.
------- LABEL 1
------- LABEL 2
------- LABEL 3

	s[0].f1 = &y;
------- LABEL 4
	return 0;
}
/*
 * Alias with array
 * Author: Sen Ye
 * Date: 06/09/2013
 */
#include "aliascheck.h"

struct MyStruct {
	int * f1;
	int * f2;
	float * f3;
};

int main() {
	struct MyStruct s[3];
	int * p[2];
	int a,b,c,d;
	float x,y;
	s[0].f1 = &a, s[0].f2 = &c, s[0].f3 = &x;
	s[1].f1 = &b, s[1].f2 = &d, s[1].f3 = &y;
	p[0] = &c, p[1] = &d;

	// Same fields of different elements in a certain
	// array are treated as one object.
------- LABEL 1
------- LABEL 2
------- LABEL 3

	// Different fields of different elements in a 
	// certain array are treated as different objects.
------- LABEL 4
------- LABEL 5

	if (a)
		s[1].f1 = &c;
------- LABEL 6

	return 0;
}
/*
 * Array alias in flow-sensitive analysis.
 * Author: Sen Ye
 * Date: 08/11/2013
 */

#include "aliascheck.h"

struct MyStruct {
	int *f1;
	int *f2;
};

int main() {
	struct MyStruct s[2];
	int x, y;
	s[0].f1 = &x;
	s[1].f2 = &y;

	s[0].f1 = &y;
------- LABEL 1
	return 0;
}
/*
 * Alias with array
 * Author: Sen Ye
 * Date: 06/09/2013
 */
#include "aliascheck.h"

struct MyStruct {
	int * f1;
	int * f2;
};

int main() {
	struct MyStruct s[2];
	int a,b,c,d;
	s[0].f1 = &a, s[0].f2 = &c;//, s[0].f3 = &x;

	if (a)
		s[1].f1 = &c;
------- LABEL 1
	return 0;
}
/*
 * Alias with array
 * Author: Sen Ye
 * Date: 06/09/2013
 */
#include "aliascheck.h"

struct MyStruct {
	int * f1;
	int * f2;
};

int main() {
	struct MyStruct s[3];
	int a,b,c,d;
	s[0].f1 = &a, s[0].f2 = &c;//, s[0].f3 = &x;
	s[1].f1 = &b, s[1].f2 = &d;//, s[1].f3 = &y;

	if (a)
		s[1].f1 = &c;
------- LABEL 1

	return 0;
}
/*
 * Alias due to lack of context-sensitivity.
 * Author: Sen Ye
 * Date: 06/09/2013
 */
#include "aliascheck.h"

void foo(int *m, int *n)
{
------- LABEL 1
	int x, y;
	x = *n;
	y = *m;
	*m = x;
	*n = y;
}

int main()
{
	int *p, *q;
	int a, b, c;
	if (c) {
		p = &a;
		q = &b;
		foo(p,q);
	}
	else {
		p = &b;
		q = &c;
		foo(p,q);
	}
	return 0;
}
/*
 * Alias due to lack of path-sensitivity.
 * Author: Sen Ye
 * Date: 06/09/2013
 */
#include "aliascheck.h"

int main()
{
	int *p, *q;
	int a, b, c;
	if (c) {
		p = &a;
		q = &b;
	}
	else {
		p = &b;
		q = &c;
	}
------- LABEL 1
	return 0;
}
/*
 * Branches for testing flow-sensitive analysis.
 * Author: Sen Ye
 * Date: 08/11/2013
 */

#include "aliascheck.h"

int main() {
	int *p, *q;
	int x, y;
	if (x)
		p = &x;
	else
		p = &y;
	q = &y;
------- LABEL 1
	return 0;
}
/*
 * Branches for testing flow-sensitive analysis.
 * Author: Sen Ye
 * Date: 08/11/2013
 */

#include "aliascheck.h"

int main() {
	int *p, *q;
	int x, y;
	q = &y;
	if (x) {
		p = &x;
------- LABEL 1
	}
	else {
		p = &y;
------- LABEL 2
	}
	return 0;
}
/*
 * Branches for testing flow-sensitive analysis.
 * Author: Sen Ye
 * Date: 08/11/2013
 */

#include "aliascheck.h"

int main() {
	int **p, **q;
	int *x, *y;
	int x0, y0;
	if (x0) {
		p = &x;
		q = &y;
------- LABEL 1
	}
	else {
		p = &y;
		q = &x;
------- LABEL 2
	}
------- LABEL 3
	return 0;
}

/// Test case from https://github.com/SVF-tools/SVF/issues/524
/// Compile this c file using `clang -S -emit-llvm -O3 byteoffset1.c`

__attribute__((noinline))
void MAYALIAS(void* p, void* q){
  printf("%c%c\n", p, q);
}

typedef struct StructA
{
    int foo;
    int (*f)(void);
} StructA;

__attribute__((noinline))
int FuncA() {
    return 1;
}

__attribute__((noinline))
int CallF(StructA *structA) {
    int ret = structA->f();
------- LABEL 1
    return ret;
}

int main() {
    StructA *structA = malloc(sizeof(StructA));
    structA->f = FuncA;

    int ret = CallF(structA);
    return ret;
}/*
 * Alias due to function pointer resolution.
 * Author: Sen Ye
 * Date: 06/09/2013
 */
#include "aliascheck.h"

void f(int *m, int *n)
{
------- LABEL 1
}

typedef void (*fp)(int*m, int*n);

int main()
{
	int a,b,c,d;
	int *pa, *pb;
    fp p;
	pa = &a, pb = &b;
	f(pa, pb);
    p = f;
	pb = &a;
    (*p)(pa, pb); 
	return 0;
}

/*
 * Context-insensitive.
 * Author: Sen Ye
 * Date: 10/10/2013
 */

#include "aliascheck.h"

int global;
int *p_global;

void foo() {
	p_global = &global;
}

int main() {
	int *p_local;
	p_local = &global;
	foo();
------- LABEL 1
	return 0;
}
/*
 * Alias due to context-insensitive
 * Author: Sen Ye
 * Date: 06/09/2013
 */
#include "aliascheck.h"

void foo(int *m, int *n)
{
------- LABEL 1
}

int main()
{
	int *p, *q;
	int a,b;
	if (a) {
		p = &a;
		q = &b;
		foo(p,q);
	}
	else {
		p = &b;
		q = &a;
		foo(p,q);
	}
	return 0;
}
/*
 * Field cycle.
 * Author: Sen Ye
 * Date: 10/10/2013
 */

#include <stdlib.h>
#include "aliascheck.h"

struct MyStruct {
	int * f1;
	struct MyStruct * next;
};

int main() {
	struct MyStruct * p = (struct MyStruct *) malloc (sizeof(struct MyStruct));
	int num = 10;
	while (num) {
		p->next = (struct MyStruct *) malloc (sizeof(struct MyStruct));
		p->next->f1 = (int *) malloc (sizeof(int));
		p = p->next;
	}
	struct MyStruct *q = p;
------- LABEL 1
------- LABEL 2
	return 0;
}

#include "aliascheck.h"
int* foo(int* x){
   return x;
}

int main(){

  int *x,*y,*p,*q,a,b;
  p = &a;
  q = &b;
  x = foo(p);
  y = foo(q);
------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4

}
#include "aliascheck.h"
void foo(int **x, int **y){

	x = y;
}

int main(){

	int *a, *b;
	int a1, b1;
	a = &a1;
	b = &b1;
	foo(a,b);
------- LABEL 1
}
#include "aliascheck.h"
int obj, t,s;
void foo(int**, int**);
main(){
	int **x, **y;
	int *a, *b, *c, *d,*e;
	x=&a; y =&b; 
	foo(x,y);
------- LABEL 1
	*b = 5;
	c=&s;
	//a=c;
	if(t) { x =&c; y =&e;}
	else { x= &d; y = &d;}
	foo(x,y);
------- LABEL 2
------- LABEL 3
	*e = 10;
	
}

void foo(int **p, int **q){
	*q = &obj;
}
