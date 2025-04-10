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
#include "aliascheck.h"
void foo(int**a, int*b){

	*a = b;

}


void main(){

	int *p,q,*x,y;
	foo(&p,&q);
------- LABEL 1
	foo(&x,&y);
------- LABEL 2
------- LABEL 3
------- LABEL 4

	*p = 100;

}
#include "aliascheck.h"
int obj;
void foo(int**, int**);
main(){
	int **x, **y;
	int *a, *b, *c, *d,*e;
	x=&a; y =&b; 
	foo(x,y);
------- LABEL 1
	x = &c;
	foo(x,y);
------- LABEL 2
	
}

void foo(int **p, int **q){
	*p = &obj;
}
#include "aliascheck.h"
void foo(int*);
int ss = 20;
int main(){
    int *a,*b,obj,t;
    a=&obj;
    foo(a);
    *a=200;
    b=&t;
    foo(b);
------- LABEL 1
------- LABEL 2
}

void foo(int* x){
     static int* k =&ss;
    printf("%d\n", *k);
    *k=200;
    k=x;
     *x= 100;
}
#include "aliascheck.h"
void foo(int*,int*);
main(){
	int*x, *y;
	int a,b, c;
	if(c)x=&a; 
	else x=&b;
------- LABEL 1
------- LABEL 2
	foo(x,y);
	x = &c;
	foo(x,y);
------- LABEL 3
------- LABEL 4
------- LABEL 5
	
}

void foo(int *p,int*q){
	*p = 100;
}
#include "aliascheck.h"

void foo(int **w,int**x,int **y, int *z){
	int *t;
	*y = z;
	t = *x;
	*w = t;

}

void bar(int **p1,int**p2,int **p3, int *p4){
	foo(p1,p2,p3,p4);
}

int main(){

	int **a,**b,**c,*d,*a1,*b1,*c1,d1;
	a = &a1;
	b = &b1;
	c = &b1;
	d = &d1;
	bar(a,b,c,d);
------- LABEL 1
------- LABEL 2
//	foo(a,b,c,d);
//	foo(b,a,c,d);
}
#include "aliascheck.h"
int *alloc( int size){

	return malloc(1);

}

void foo(int **p){

	*p = alloc(1);
	//*p = alloc();

}

void main(){

	int *a,*b,*c;
	foo(&a);
	foo(&b);
	foo(&c);
------- LABEL 1
------- LABEL 2
------- LABEL 3

}
#include "aliascheck.h"
void bar(int**k, int**s){

	*k = *s;

}

void foo(int**x,int**y,int**z){
	int t;
	*y = &t;
	*z = *x;
}

int main(){
	int *p1,*q1,*r1,*a1,*b1,*c1,q2,a2;
	int **p = &p1;
	int **q = &q1;
    q1 = &q2;
	int **r = &r1;
	int **a = &a1;
    a1 = &a2;
	int **b = &b1;
	int **c = &c1;
	bar(&p,&q);
------- LABEL 1
------- LABEL 2
	foo(p,q,r);
------- LABEL 3
	foo(a,b,c);
------- LABEL 4
------- LABEL 5
------- LABEL 6

}
#include "aliascheck.h"
int obj,b;
void bar(int **s){
    *s = &b;
}

void foo(int **p){
	*p = &obj;
	bar(p);
}
main(){
	int **x;
	int *a, *c;
	x=&a; 
	foo(x);
------- LABEL 1
------- LABEL 2
	x = &c;
	foo(x);
------- LABEL 3
------- LABEL 4
	
}

#include "aliascheck.h"
int g;
int* obj = &g;
void Zulu(int**p, int *q);
 
void Xray(){

	int **x,*b,*w,d;
	x = &b;
	w = &d;
	Zulu(x,w);
------- LABEL 1
------- LABEL 2
}


void Zulu(int**p,int *q){

	*p = q;
    *p = obj;
}

void main(){

	Xray();

}
#include "aliascheck.h"
int obj;
void foo(int **p, int **q, int **r){


	*r = *p;
	*q = &obj;

}


void main(){

	int **a,**b,**c,**d,**e,**f,*x,*y,*z,*w,*k,x1,y1,z1,w1,k1;
	x = &x1;
	y = &y1;
	z = &z1;
	w = &w1;
	k = &k1;

	a = &x;
	b = &y;
	c = &z;
	if(a){

		d = &w;
		e = &w;
		f = &k;
	}
	foo(a,b,c);
------- LABEL 1
------- LABEL 2
	foo(d,e,f);
------- LABEL 3
------- LABEL 4
------- LABEL 5
------- LABEL 6
------- LABEL 7

}
#include "aliascheck.h"
int *obj;
int **x,*b,*w,d;
int **z, *a,*y,c;
void Zulu(int**p, int *q);
 
void Xray(){
	x = &b;
	w = &d;
	Zulu(x,w);
------- LABEL 1
------- LABEL 2
}

void Yank(){
	z = &a;
	y = &c;
	Zulu(z,y);
------- LABEL 3
------- LABEL 4
}

void Zulu(int**p,int *q){
	*q = 100;
	*p = q;

}

void main(){

	Xray();
	Yank();

}
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
#include "aliascheck.h"
void foo(int **p, int **q, int **r,int *s){

	*r = *p;
	*q = s;

}


void main(){

	int **a,**b,**c,**d,**e,**f,*x,*y,*z,*w,*g,*k,x1,y1,z1,w1,k1,g1;
	x = &x1;
	y = &y1;
	z = &z1;
	w = &w1;
	g = &g1;
	k = &k1;

	a = &x;
	b = &y;
	c = &z;

	foo(a,b,c,k);
------- LABEL 1
------- LABEL 2
	d = &w;
	e = &w;
	f = &g;
	foo(d,e,f,k);
------- LABEL 3
------- LABEL 4
------- LABEL 5
------- LABEL 6
------- LABEL 7

}
#include "aliascheck.h"
void foo(int **x,int**y,int **z, int *w){
	int *t;
	*y = w;
	t = *x;
	*z = t;

}

int main(){

	int *a,*b,*c,d,*p,*q,r,a1;
    a = &a1;
	foo(&a,&b,&c,&d);
------- LABEL 1
------- LABEL 2
	foo(&p,&p,&q,&r);
------- LABEL 3
------- LABEL 4
------- LABEL 5
------- LABEL 6
}
#include "aliascheck.h"
int** g;

void foo(int **p, int *q){
	g = q;
	*p = g;
}

int main(){
	int **a,*b,*a1,b1;
	a = &a1;
	b = &b1;
	foo(a,b);
------- LABEL 1
}
#include "aliascheck.h"
void foo(int **p, int **q){

	*q = *p;

}


void main(){

	int **a,**b,**c,**d,**e,**f,*x,*y,*z,*w,*k,x1,y1,z1,w1,k1;
	x = &x1;
	y = &y1;
	w = &w1;
	k = &k1;

	a = &x;
	b = &y;
	c = &w;
	d = &k;

	foo(a,b);
------- LABEL 1
	foo(c,d);
------- LABEL 2
------- LABEL 3
------- LABEL 4

}
#include "aliascheck.h"
int obj1,obj2;
void foo(int **p, int **q){

	*p = &obj1;
	*q = &obj2;

}

int main(){

	int **a,**b,*x,*y,*z;
	if(a){
		a = &x;
		b = &y;
	}
	else{
		a = &z;
		b = &z;
	}
	foo(a,b);
------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4
------- LABEL 5

}
#include "aliascheck.h"
int obj, t,s;
int *k =&s;
void foo(int**, int**);
main(){
	int **x, **y;
	int *a, *b, *c, *d,*e;
    a = &t;
	x=&a; y =&b; 
	foo(x,y);
------- LABEL 1
------- LABEL 2
	*b = 5;
	c=&t;
	c=&s;
	a=c;
------- LABEL 3
	if(t) {c=&obj; x =&c; y =&e;}
	else { x= &d; y = &d;}
	e = &t;
	foo(x,y);
------- LABEL 4
------- LABEL 5
------- LABEL 6
------- LABEL 7
------- LABEL 8
	*e = 10;
	
}

void foo(int **p, int **q){
	*p = *q;
	*q = &obj;
}
/*
 * Pointer arithmetic
 * Author: Sen Ye
 * Date: 06/09/2013
 */
#include "aliascheck.h"

struct s {
	int* f1;
	int* f2;
};

int main()
{
	int **q, **p;
	int a,b;
	struct s s1;
	s1.f1 = &a;
	s1.f2 = &b;
	q = &(s1.f1);
	p = q+1;
------- LABEL 1
	return 0;
}
/*
 * Pointer arithmetic
 * Author: Sen Ye
 * Date: 06/09/2013
 */
#include "aliascheck.h"

struct s {
	int* f1;
	int* f2;
};

int main()
{
	int **q, **p;
	int a,b;
	struct s s1;
	s1.f1 = &a;
	s1.f2 = &b;
	q = &(s1.f1);
	// b is not a constant, p would point to all
	// the fields of q's points-to targets
	p = q+b;
------- LABEL 1
	return 0;
}
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

/*
 * Function pointer.
 * Author: Sen Ye
 * Date: 10/10/2013
 */
#include "aliascheck.h"

void func1(int *p, int *q) {
	// if function pointer solved correctly,
	// p and q will alias due to CS1
------- LABEL 1
	*p = *q;
}

void (*fp)(int*,int*);

int main() {
	int x, y;
	int *m, *n;
	if (x) {
		m = &x, n = &x;
		fp = func1;
		fp(m,n); // CS1
	}
	else {
		m = &x; n = &y;
//		func1(m,n); // CS2
	}
	return 0;
}
/*
 * Function pointer.
 * Author: Sen Ye
 * Date: 10/10/2013
 */
#include "aliascheck.h"


void func1(int **p, int **q) {
	*p = *q;
------- LABEL 1
}

void (*fp)(int**,int**);

int main() {
	int o1, o2;
	int *x, *y;
	int **m, **n;
	x = &o1;
	y = &o2;
	m = &x;
	n = &x;
	fp = func1;
	fp(m,n);
------- LABEL 2
	return 0;
}
/*
 * functionpointer1.c
 * Test function pointer with field initialization of globals
 *
 *  Created on: 01/09/2015
 *      Author: Yulei Sui
 */
#include "aliascheck.h"

typedef int PRSize;
typedef unsigned int PRUint32;
typedef unsigned int PRUintn;
typedef int PRIntn;

struct PLHashAllocOps {
   void *(*allocTable)(void *pool , PRSize size ) ;
};
typedef struct PLHashAllocOps PLHashAllocOps;

static void *DefaultAllocTable(void *pool , PRSize size )
{ void *tmp ;

  {
  tmp = malloc((unsigned int )size);
  return (tmp);
}
}

PLHashAllocOps defaultHashAllocOps  =    {& DefaultAllocTable};
void PL_NewHashTable(PRUint32 n , void *allocPriv )
{
  void *tmp___0 ;
  void *tmp___1 ;

  PLHashAllocOps const   * allocOps = (PLHashAllocOps const   *)(& defaultHashAllocOps);
  tmp___0 = (*(allocOps->allocTable))(allocPriv, (int )sizeof(int));
  tmp___1 = (*(allocOps->allocTable))(allocPriv, (int )sizeof(int));
------- LABEL 1

}

int main(){return 0;}

------- LABEL 1
struct interesting {
        int dummy;
        void (*f1)(int*);
        void (*f2)(int*);
};

struct nested_ptr {
        int dummy;
        struct interesting* ptr;
};

int g;
------- LABEL 2
------- LABEL 3

struct interesting i1 = {
        .f1 = f1,
        .f2 = f2
};

struct nested_ptr n1 = {
        .ptr = &i1
};

void test_ptr() {
        struct interesting interesting_stub = *n1.ptr;
        interesting_stub.f1(&g);
        interesting_stub.f2(&g);
}
------- LABEL 1
struct interesting {
        int dummy;
        void (*f1)(int*);
        void (*f2)(int*);
};

struct nested_ptr {
        int dummy;
        struct interesting* ptr;
};

int g;
------- LABEL 2
------- LABEL 3

struct interesting i1 = {
        .f1 = f1,
        .f2 = f2
};

struct nested_ptr n1 = {
        .ptr = &i1
};

void test_ptr() {
        struct nested_ptr tmp = n1;
        struct interesting interesting_stub = *tmp.ptr;
        interesting_stub.f1(&g);
        interesting_stub.f2(&g);
}
/*
 * Function pointer.
 * Author: Sen Ye
 * Date: 10/10/2013
 */
#include "aliascheck.h"

void f(int *p, int *q) {
	// if function pointer solved correctly,
	// p and q will alias due to CS1
------- LABEL 1
}

void (*fptr)(int*,int*);

int main() {
	int x, y;
	int *m, *n;
	if (x) {
		m = &x, n = &x;
		fptr = f;
		fptr(m,n); // CS1
	}
	else {
		m = &x; n = &y;
		f(m,n); // CS2
	}
	return 0;
}
#include <stdio.h>
#include "aliascheck.h"
int g;
static int my_sn_write(int* p) {
	  printf("Executing my_sn_write\n");
------- LABEL 1
	    return 0;
}

struct MYFILE {
	  int (*pt) (int* p);
};

void my_vfprintf(struct MYFILE *pts) {
	  printf("Executing bar\n");
	  int *p = &g;
	    pts->pt(p);
}

int my_vsnprintf() {
	  struct MYFILE pts = { .pt = my_sn_write };
	    my_vfprintf(&pts);
	      return 0;
}

int main() {
	  my_vsnprintf();
	    return 0;
}

/*
 * Global variables test.
 * Author: Sen Ye
 * Date: 03/05/2014
 */
#include "aliascheck.h"

int *p = NULL;
int *q = NULL;
int c;

void foo() {
------- LABEL 1
}

void bar() {
	q = &c;
}

int main() {
	int a, b;
	p = &a;
	q = p;
	p = &c;
}
/*
 * Global variables test.
 * Author: Sen Ye
 * Date: 07/05/2014
 */
#include "aliascheck.h"

struct MyStruct {
	char f0[20];
	int f1;
	int* f2;
};

int x, y;
struct MyStruct global = {"abcdefg", 20, &x};

void foo(int** pp, int** qq) {
	*pp = &x;
	*qq = &y;
}

void bar(int** pp, int** qq) {
	*pp = &x;
	*qq = &x;
}

int main() {
	int *p, *q;
	int **pp, **qq;
	pp = &p;
	qq = &q;
	bar(pp,qq);
------- LABEL 1
------- LABEL 2
}
/*
 * Global variables test.
 * Author: Sen Ye
 * Date: 07/05/2014
 */
#include "aliascheck.h"

struct MyStruct {
	int f1;
	void (*fp)(int**, int**);
};

struct MyStruct global;
int x, y;

void foo(int** pp, int** qq) {
	*pp = &x;
	*qq = &y;
}

void bar(int** pp, int** qq) {
	*pp = &x;
	*qq = &x;
}

void init() {
	global.fp = foo;
}

void init2() {
	global.fp = bar;
}

void run(int** pp, int**qq) {
	(*global.fp)(pp, qq);
}

int main() {
	int *p, *q;
	int **pp, **qq;
	pp = &p;
	qq = &q;
	init();
	run(pp, qq);
	// They are alias due to the wrongly solved
	// target, bar(), at indirect call site in
	// run().
------- LABEL 1
}
