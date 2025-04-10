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
/*
 * Global variables with function pointer initialisation.
 * Author: Sen Ye
 * Date: 07/05/2014
 */
#include "aliascheck.h"

int x, y;
int* p;

void foo() {
	p = &y;
}

struct MyStruct {
	void (*fp)();
	int* f1;
};

struct MyStruct context = { foo, &x };

int main()
{
	(*context.fp)();
	int* q = p;
------- LABEL 1
	return 0;
}
/*
 * Global variable
 * Author: Sen Ye
 * Date: 13/10/2013
 * Description: initialise global variables when declared
 *		and check alias in main function.
 */
#include "aliascheck.h"

int x;
int *p, *q;
int **pp = &p;
int **qq = &q;

void foo() {
	p = &x;
}

void bar() {
	q = &x;
}

int main() {
------- LABEL 1
	foo();
	bar();
	return 0;
}
/*
 * Global variable
 * Author: Sen Ye
 * Date: 13/10/2013
 * Description: Initialise global variables in callee and check alias
 *		in caller.
 */
#include "aliascheck.h"

int **pp, **qq;
int *p, *q;
int x;

void foo() {
	pp = &p;
	p = &x;
}

void bar() {
	qq = &q;
	q = &x;
}

int main() {
------- LABEL 1
	foo();
	bar();
	return 0;
}
/*
 * Global variables test.
 * Author: Sen Ye
 * Date: 03/05/2014
 */
#include "aliascheck.h"

int a_int = 10;
int* p_int = &a_int;
int** pp_int = &p_int;

int main() {
	int b_int = a_int;
	int* q_int = p_int;
	int** qq_int = pp_int;
------- LABEL 1
------- LABEL 2
	return 0;
}
/*
 * Global pointer in flow-sensitive analysis.
 * Author: Sen Ye
 * Date: 08/11/2013
 */

#include "aliascheck.h"

int x, y; int *p = &x; int *q = &y;
int **pp = &p; int**qq = &q;

void foo() {
------- LABEL 1
}
void bar() {
     qq = &q;
     q = &x;
}
int main() {
    foo();
    bar();
------- LABEL 2
}

/*
 * Global pointer in flow-sensitive analysis.
 * Author: Sen Ye
 * Date: 08/11/2013
 */

#include "aliascheck.h"

int **pp, **qq;
int *p, *q;
int x, y;

void foo() {
	pp = &p;
	p = &x;
	qq = &q;
	q = &y;
------- LABEL 1
}

void bar() {
	qq = &q;
	q = &x;
}

int main() {
	foo();
	bar();
------- LABEL 2
	return 0;
}
/*
 * Global pointer in flow-sensitive analysis.
 * Author: Sen Ye
 * Date: 08/11/2013
 */

#include "aliascheck.h"

int **pp, **qq;
int *p, *q;
int x;

void foo() {
	*pp = &x;
}

void bar() {
	qq = &q;
	q = &x;
}

int main() {
	pp = &p;
	foo();
	bar();
------- LABEL 1
	return 0;
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

int main(){
	Xray();
	return 0;
}
/*
 * Global pointer in flow-sensitive analysis.
 * Author: Sen Ye
 * Date: 08/11/2013
 */

#include "aliascheck.h"

int **pp, **qq;
int *p, *q;
int x;

void foo() {
	pp = &p;
	p = &x;
}

void bar() {
	qq = &q;
	q = &x;
}

int main() {
	foo();
	bar();
------- LABEL 1
	return 0;
}
/*
 * Heap
 * Author: Sen Ye
 * Date: 12/10/2013
 * Description: heap objects are identified according to their
 *		allocation sites.
 */
#include "aliascheck.h"

// return two malloc object
void malloc_two(int **p, int **q) {
	*p = (int*) malloc(sizeof(int));
	*q = (int*) malloc(sizeof(int));
}

int main() {
	int **o1 = malloc(100);
    int **o2 = malloc(100);
	malloc_two(o1, o2);
------- LABEL 1
	return 0;
}
/*
 * Heap
 * Author: Sen Ye
 * Date: 15/10/2013
 * Description: heap objects are identified according to their
 *		allocation sites.
 */
#include "aliascheck.h"

struct Node {
	int *data;
	struct Node *next;
};

// return two malloc object
void malloc_list(struct Node *p, int num) {
	int *p_data1=NULL, *p_data2=NULL;
	struct Node *p_next = NULL;
    p->data = NULL;
	while (num!=0) {
		p->data = (int *) malloc(sizeof(int));
		p_data1 = p->data;
	    p_next = (struct Node*) malloc(sizeof(struct Node));
		p->next = p_next;
		p_data2 = p->data;
        num--;
	}
------- LABEL 1
------- LABEL 2
}

int main() {
	struct Node* head = (struct Node*) malloc(sizeof(struct Node));
	int num = 4;
	malloc_list(head, num);
------- LABEL 3
	return 0;
}
/*
 * Heap
 * Author: Sen Ye
 * Date: 12/10/2013
 * Description: heap objects are identified according to their
 *		allocation sites.
 */
#include "aliascheck.h"

// return one malloc object
int * my_alloc() {
	int * p = (int *) malloc(sizeof(int));
	return p;
}

int main() {
	int * o1 = my_alloc();
	int * o2 = my_alloc();
------- LABEL 1
	return 0;
}
/*
 * Alias due to casting between
 * integer and pointer.
 * Author: Sen Ye
 * Date: 06/09/2013
 */

#include "aliascheck.h"

struct MyStruct {
	int f1;
	int f2;
};

int main() {
	struct MyStruct ms;
	int *p, *q;
	p = &(ms.f1);
	// cast pointer to integer
	int addr = (int)p;
	// cast integer to pointer and
	// q would point to blackhole
	q = (int*)addr + 1;
------- LABEL 1
	return 0;
}
#include "aliascheck.h"

void foo(int**, int*);
main(){
	int **x, *y;
	int  *c, *d,e,f;
	if(x) { x =&c; y =&e;}
	else { x= &d; y = &f;}
	foo(x,y);
------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4
	
}

void foo(int **p, int *q){
	*p = q;
}
#include "aliascheck.h"

void foo(int** s);
void bar(int** s);
int k;
int main(){

    int **p,*q;
    int *b,*c,e;
    if(e){
        p = &b;
        foo(&q);
    }
    else{
        p = &c;
        q = &e;
    }

    *p = q;
------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4
}

void foo(int**x){
    bar(x);
}

void bar(int**s){
    *s = &k;
}
#include "aliascheck.h"

void foo(int**,int* );
int main(){

    int **p,*q;
    int *a,*b,c,d;
    if(a){
        p = &a;
        q = &c;
        foo(p,q);
    }
    else{
        p = &b;
        q = &d;
        foo(p,q);
    }

    *p = q;
------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4
}

void foo(int**x,int *y){
    *x = y;
}

#include "aliascheck.h"

int obj, t,s;
void foo(int**, int**);

void main(){
	int **x, **y;
	int *a, *b, *c, *d,*e;
	e = &t; d = &obj;
	c = &s;
	if(t) { x =&c; y =&e;}
	else { x= &d; y = &d;}
    foo(x,y);
------- LABEL 1
------- LABEL 2
	
}

void foo(int **p, int **q){
	*p = *q;
}
#include "aliascheck.h"

struct agg{
	int **i;
}agg;

int main(){
	int *b,*c,*d,f,w;
	struct agg ag1, *a;
	a = &ag1;

	if(a){
        if(f){
		    a->i = &c;
		    b = &f;
        }
	}
	else{
		a->i = &d;
		b = &w;
	}
	*(a->i) = b;
------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4
}
/*
 * Cycle
 * Author: Sen Ye
 * Date: 11/10/2013
 */
#include "aliascheck.h"

int main() {
	int **x1, **y1, **z1;
	int *x2, *y2, *z2, *y2_;
	int x3, y3, z3, y3_;
	x2 = &x3, y2 = &y3, z2 = &z3;
	x1 = &x2, y1 = &y2, z1 = &z2;
	// if the following branch is commented out,
	// the first alias check will fail while
	// the second one is OK.
	if (y3_) {
		y1 = &y2_;
		y2_ = &y3_;
	}
	*x1 = *y1;
	*y1 = *z1;
	*z1 = *x1;
	// there should be a cycle from
	// y2 -> x2 -> z2 -> y2
------- LABEL 1
------- LABEL 2
	return 0;
}
#include "aliascheck.h"
int** g;

void foo(int **p, int *q){
	g = p;
	*g = q;

}

int main(){
	int **a,*b,*a1,b1;
	a = &a1;
	b = &b1;
	foo(a,b);
------- LABEL 1
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

struct MyStruct {
    const struct MYFILE *myfile;
};

const struct MYFILE pts = { .pt = my_sn_write };
const struct MyStruct ms = { .myfile = &pts };

void my_vfprintf(const struct MyStruct *ms) {
    printf("Executing bar\n");
    int *p = &g;
    ms->myfile->pt(p);
}

int main() {
    my_vfprintf(&ms);
    return 0;
}

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
#include "aliascheck.h"
void foo(int q){
  int i = 10;
  int k = i;

}
int main(){

int *s,*r,*x,**y,t,z,k;
	s = &t;
	r = &z;
	y = &r;
	s = r;
------- LABEL 1
	x = *y;
------- LABEL 2
	foo(k);
return 0;
}
/*
 * Struct with array.
 * Author: Sen Ye
 * Date: 28/04/2014
 */
#include "aliascheck.h"

struct ArrayStruct {
	int f1;
	char f2;
	int f3[100];
	int f4;
};

int main() {
	struct ArrayStruct* p;
	struct ArrayStruct s;
	int* q;

	p = &s;
	q = &s.f3[40];
------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4
	
	return 0;
}
#include "aliascheck.h"

int main(){
    int **p, *q, **w,*v, *a,a1,q1;
    a = &a1;
    p = &a;
    q = &q1;
    w = 0;
    if(p)
        *p = q;
    else
        w = &a;

    v = *w;
------- LABEL 1
------- LABEL 2

}
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
#include "aliascheck.h"
int x,y,*q,*f,*e,d;

void foo(int **p){
	f = &x;
	if(x){
		p = &e;
		f = &y;
	}

	*p = f;
------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4
------- LABEL 5
}



int main(){
	int **a,c;
	a = &q; f = &d;	
	foo(a);
}

#include "aliascheck.h"
int y,*q,*r,*f,*e,c,d;

void foo(int **p){

    if(y){
		p = &e;
		f = &y;
	}

	*p = f;
------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4
------- LABEL 5
}



int main(){
	int **a,**b;
    e = 0;
	a = &q; f = &d;	
	foo(a);
    b = &r; f = &c;
    foo(b);
------- LABEL 6
------- LABEL 7
------- LABEL 8
------- LABEL 9
}

#include "aliascheck.h"

int main(){

    int **p,**q;
    int *a,*b;
    int *m,*n;
    int a1,b1,m1;

    a = &a1;
    b = &b1;
    m = &m1;
	p = &a;
	q = &b;

    if(a){
	    p = &b;
	    q = &a;
    }

    *p = m;
	n = *q;
------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4
------- LABEL 5
------- LABEL 6
}
#include "aliascheck.h"
int main(){

    int**a,**b, *f,*g,r,w,q,*obj,k;
    f = &k;
    if(a){
        a = &f;
        f = &r;
    }
    else{
        a = &g;
        g = &w;
    }
    a = b;

    *a = &q;
    obj = *b;
------- LABEL 1
------- LABEL 2
------- LABEL 3

}
#include "aliascheck.h"
int main(){
    int ***p,**a,**b,*q,*r,*f,v,z,*g,f1; 

    p = &a;
    a = b = &f;
    f = &f1;
    q = &v;

    if(a){
        f = &z;
        *p = &g;
        b = *p;
    }
    else{


    }

    *a = q;
    r = *b;
------- LABEL 1
------- LABEL 2
------- LABEL 3
}
#include "aliascheck.h"

void foo(int ***,int**);
int obj;
int main(){

    int ***p,**q, **a, **b, *c, *m,*n,d;
    m = &d;
    a = b = &c;
    if(a){
        p = &a;
        q = &c;
        foo(p,q);
    }
    else{
        p = &b;
        q = &c;
        foo(p,q);
    }

   *a = m;
   n = *b;
------- LABEL 1
------- LABEL 2
}

void foo(int ***x,int **y){
    *x = y;
}
#include "aliascheck.h"

int main(){

    int **p,**q;
    int *a,*b;
    int *m,*n;
    int a1,b1,m1;

    a = &a1;
    b = &b1;
    m = &m1;
	p = q = &a;

    if(a){
	    p = q = &b;
    }

    *p = m;
	n = *q;
------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4
------- LABEL 5
}
#include "aliascheck.h"


int main(){

    int **p,**q;
    int **x,**y;
    int *a,*b,*x1,a1,b1;
    int *m,*n,n1;
    /// Note that n needs to be initialized
    n = &n1;
    a = &a1;
    b = &b1;
    x = y = &x1;
    p = q = &a;
    if(a){
        p = x;
        q = y;
    }

    *p = n;
    m = *q;

------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4
------- LABEL 5

}
#include "aliascheck.h"

struct agg{
    int*pi;
    int k;
}agg;

int main(){
    int *s,k1,k2;
    struct agg *a,*b, obj1,obj2;
    /// Note that, all pointers should be properly initialized
    /// the path information uninitialized value are not fully maintained on LLVM PHINode after mem2reg
    a = b = 0;
    if(k1){
        a = &obj1;
        s=&k1;
    }
    else{
        b = &obj2;
        s=&k2;
    }

    a->pi = s;
    b->pi = s;
------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4
}
#include "aliascheck.h"

int main(){
    int **p,*q;
    int *a,*b,c,d;
    if(a){
        p = &a;
        q = &c;
    }
    else if(b) {
        p = &b;
        q = &d;
    }
    else{
      printf("dummy branch\n");
    }
    *p = q;
------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4
}
#include "aliascheck.h"

int main(){

    int **p,*q;
    int *b,*c,d,e;

    p = &c;
    q = &e;

    if(d){
        p = &b;
    }
    else{
        q = &d;
    }

    *p = q;

------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4
}
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
#include "aliascheck.h"

typedef struct subagg1{
    int *d;
}subagg1;

typedef struct agg1{
    int *c;
    subagg1 sub;
}agg1;

int main(){
    int *a,*b,k1,k2;
    agg1 g1,g2;
    agg1 *g = &g1;

    if(k1){
        g = &g2;
        a = &k1;
    }
    else{
        a = &k2;
    }

    g->sub.d = a;
------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4

}
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
/*
 * Simple alias check
 * Author: Sen Ye
 * Date: 06/09/2013
 */
#include "aliascheck.h"

int main()
{
	int a,b,*c,*d;
	c = &a;
	d = &a;
------- LABEL 1
	c = &b;
	// In LLVM, every declared variable is address-taken 
	// accessed via pointers through loads/stores
	// c here is loaded from the same memory on LLVM's partial SSA form
------- LABEL 2
------- LABEL 3
	return 0;
}
#include "aliascheck.h"

int main(){

  int **a, *b, *x ,c;
  c = 10;
  a = &b;
  b = &c;
  x = *a;
  int y = *x;
------- LABEL 1
------- LABEL 2
  return 0;
}
#include "aliascheck.h"
int *x, y, z;

void f() {
  if(z > 5) return;
  z++;
  if (1) {
         x = &y;
------- LABEL 1
          f();
         x = &z;
------- LABEL 2
------- LABEL 3
          f();
  }
}


int main()
{
           f();
	   return 0;
}
#include "aliascheck.h"
int **p,*x, y, z;

void f() {
  p = &x;
  if (z) {
    *p = &y;
------- LABEL 1
    f();
    *p = &z;
------- LABEL 2
------- LABEL 3
    f();
  }
}


int main()
{
    f();
    return 0;
}
#include "aliascheck.h"
int* x,y;
void f(int *m){
------- LABEL 1
	int *n;
	if(y==1){
		n=&y;

		f(n);
	}
}

int main(){
	x=&y;
	f(x);
}
#include "aliascheck.h"
int x, *y, z;
void f(int **m);
void main(){

	int **a = &y;

	f(a);


}

void f(int **m){
	if(x){
		*m = &x;
------- LABEL 1
------- LABEL 2
		f(m);
	}
	else{
		*m = &z;
------- LABEL 3
------- LABEL 4
	}

}
#include "aliascheck.h" 
int **x, *y;
int z;
void f(int **p);
void main(){
	x = &y;
	f(x);
}


void f(int **p){
	int k;
	y = &k;
	if (z){
		*p = &z;
------- LABEL 1
------- LABEL 2

		f(p);
	}
	/// y will not alias to &z as the value flow
	/// of y after it is updated at "*p=&z" will
	/// flow into f(p) again and then be updated
	/// by the first statement "y=&k".
------- LABEL 3
------- LABEL 4

}

#include "aliascheck.h"
int* x, x1;
void f(int **m){
int **n,*y,*k,z,r;
   n = &y;
   y = &z;
   if(z==1){
	*n=&r;
------- LABEL 1
------- LABEL 2
	k = *n;
------- LABEL 3
------- LABEL 4
	f(n);
   }
}

int main(){
	x=&x1;
	f(x);
}
#include "aliascheck.h"
int *x,y,z;

void f();

int main(){
    f();
    *x=100;
}

void f(){
    
    if(z){
	x=&y;
	f();
	x=&z;
	f();
------- LABEL 1
------- LABEL 2
    }
------- LABEL 3
------- LABEL 4
}
#include "aliascheck.h"
int z1,z2;
void foo(int **p);
void bar(int **a){
	if(z1>5) return;
	z1++;
	int *c, b;
	*a = &b;
	c = *a;
------- LABEL 1
------- LABEL 2
------- LABEL 3
	foo(a);
}


void foo(int** p){

	p = malloc(10);
	*p = &z2;
	bar(p);
}

int main(){

	int **x, *y;
	x = &y;
	y = &z1;
	foo(x);
}
#include "aliascheck.h"
int z;
void foo(int **a);
void bar(int **q){
    int** a = malloc(10);
    foo(a);
}

void foo(int **a){
    if(z>5) return;
    z++;
    *a = &z;
    bar(a);
}




int main(){
    int** a,*b,*c,b1,c1;
    b = &b1;
    a = &b;
    foo(a);
------- LABEL 1
------- LABEL 2
    a = &c;
    foo(a);
------- LABEL 3
------- LABEL 4
}
/*
 * Simple program to test flow-sensitive analysis.
 * Author: Sen Ye
 * Date: 08/11/2013
 */

#include "aliascheck.h"

int main() {
	int *p, *q;
	int x, y;
	p = &x;
	q = &y;
------- LABEL 1
	p = q;
------- LABEL 2
	return 0;
}
/*
 * Simple program to test flow-sensitive analysis.
 * Author: Sen Ye
 * Date: 08/11/2013
 */

#include "aliascheck.h"

int main() {
	int *p, *q, *r;
	int x, y, z;
	p = &x;
	q = &y;
	r = &z;
------- LABEL 1
	p = q;
------- LABEL 2
	p = r;
------- LABEL 3
	return 0;
}
/*
 * Simple program to test flow-sensitive analysis.
 * Author: Sen Ye
 * Date: 08/11/2013
 */

#include "aliascheck.h"

int main() {
	int **p, **q;
	int *x, *y;
	int x0, y0;
	p = &x;
	q = &y;
	*p = &x0;
	*q = &y0;
------- LABEL 1
	*p = *q;
------- LABEL 2
	return 0;
}
/*
 * Quake benchmark
 * Loukas Kallivokas and David O'Hallaron
 * Carnegie Mellon University, November, 1997
 * http://www.cs.umd.edu/~hollings/cs714/f15/quake.c
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "aliascheck.h"
#define AMAX_NAME  128

#ifndef PI
#  define PI 3.141592653589793238
#endif

/*--------------------------------------------------------------------------*/ 

double ***disp, ***K;
double **v;
int *ARCHmatrixindex, *Acol;


int main(int argc, char **argv)
{
  int i, j, k, disptplus, pp;
  int Anext, Alast, col;
  double sum0, sum1, sum2, sum3;


	disp = (double ***) malloc( 3*sizeof(double**));
        for(disptplus = 0; disptplus < 3; disptplus++){
           disp[disptplus] = (double **) malloc( 5000*sizeof(double*));
           for(i = 0; i < 5000; i++)
              disp[disptplus][i] = (double *) malloc( 4*sizeof(double));
        }
	if(disp[2][4999] == NULL) 
	{printf("null pointer 2!\n"); return 0;}

	K = (double ***) malloc( 3*sizeof(double**));
        for(disptplus = 0; disptplus < 3; disptplus++){
           K[disptplus] = (double **) malloc( 5000*sizeof(double*));
           for(i = 0; i < 5000; i++)
              K[disptplus][i] = (double *) malloc( 4*sizeof(double));
        }
	if(K[2][4999] == NULL) 
	{printf("null pointer 2!\n"); return 0;}

        v = (double **) malloc( 5000*sizeof(double*));
        for(i = 0; i < 5000; i++)
           v[i] = (double *) malloc( 4*sizeof(double));
	if(v[4999] == NULL) 
	{printf("null pointer 2!\n"); return 0;}

        ARCHmatrixindex = (int *) malloc( 5001*sizeof(int));
	if(ARCHmatrixindex == NULL) 
	{printf("null pointer 2!\n"); return 0;}

        Acol = (int *) malloc( 4*sizeof(int));
	if(Acol == NULL) 
	{printf("null pointer 2!\n"); return 0;}

  for(disptplus = 0; disptplus < 3; disptplus++)
    for (i = 0; i < 5000; i++)
      for (j = 0; j < 4; j++){
        disp[disptplus][i][j] = 0.0;
        K[disptplus][i][j] = 1.1*i + j;
  }

  for (i = 0; i < 5000; i++)
    for (j = 0; j < 4; j++)
      v[i][j] = 1.1*i + j;

  for(i = 0; i < 5001; i=i+3){
    ARCHmatrixindex[i] = 0;
    ARCHmatrixindex[i+1] = 1;
    ARCHmatrixindex[i+2] = 2;
  }
       
  for(i = 0; i < 4; i++){
    Acol[i] = 300*i;
  }


for(pp = 0; pp < 100000; pp++){
  for (i = 0; i < 5000; i++) {

    Anext = ARCHmatrixindex[i];
    Alast = ARCHmatrixindex[i + 1];


    while (Anext < Alast) {
      col = Acol[Anext];


      disp[1][col][0] += K[Anext][0][0]*v[i][0] + K[Anext][1][0]*v[i][1] + K[Anext][2][0]*v[i][2];
      disp[1][col][1] += K[Anext][0][1]*v[i][0] + K[Anext][1][1]*v[i][1] + K[Anext][2][1]*v[i][2];
      disp[1][col][2] += K[Anext][0][2]*v[i][0] + K[Anext][1][2]*v[i][1] + K[Anext][2][2]*v[i][2];
      disp[1][col][3] += K[Anext][0][3]*v[i][0] + K[Anext][1][3]*v[i][1] + K[Anext][2][3]*v[i][2];
------- LABEL 1
------- LABEL 2
------- LABEL 3
------- LABEL 4
------- LABEL 5
      Anext++;
    }


  }
}

  double rst = disp[1][4999][2];

        for(disptplus = 0; disptplus < 3; disptplus++){
           for(i = 0; i < 5000; i++)
              free(disp[disptplus][i]);
           free(disp[disptplus]);
        }
        free(disp);

        for(disptplus = 0; disptplus < 3; disptplus++){
           for(i = 0; i < 5000; i++)
              free(K[disptplus][i]);
           free(K[disptplus]);
        }
        free(K);

        for(i = 0; i < 5000; i++)
              free(v[i]);
        free(v);

        free(ARCHmatrixindex);
        free(Acol);



  if(rst > 5.5)
    return 0;
  else
    return 1;

}
/* --------------------------------------------------------------------------*/




/*
 * Testcases from 254.gap.
 * Author: Sen Ye
 * Date: 12/05/2014
 */
#include <stdlib.h>
#include "aliascheck.h"

/// Note that `SyGetmem` is summarized lib function (with side-effect ExtAPI::EFT_ALLOC) in ExtAPI.cpp, we will use SVF's summmary instead of this user defined function
char *  SyGetmem ( long size );

typedef struct TypHeader {
	struct TypHeader    * * ptr;
}    * TypHandle;

TypHandle HdFree;
TypHandle FreeHandle;
TypHandle* FirstBag;

void IntComm () {}

TypHandle NewBag() {
	long needed;
	TypHandle *d, *s, *e;
	TypHandle h;

	d = ((TypHandle*)((HdFree)->ptr)) + needed / (sizeof(TypHandle)) - 1;
	s = ((TypHandle*)((HdFree)->ptr)) - 1;
	e = (FirstBag-1);
	while ( e <= s )  *d-- = *s--;
------- LABEL 1

	for (h=HdFree; h < (TypHandle)(FirstBag-1); ++h)
		h->ptr += needed / (sizeof(TypHandle));

	h->ptr = (TypHandle*)FreeHandle;
	FreeHandle = h;

	return FreeHandle;
}

void InstIntFunc(void (*func)()) {
	TypHandle hdDef = NewBag();
	*(void(**)())((TypHandle*)((hdDef)->ptr)) = func;
}

void InitGasman() {
	long SyMemory;
	HdFree = (TypHandle)SyGetmem( SyMemory );
	FreeHandle = (TypHandle)((TypHandle*)((FreeHandle)->ptr));
}

int main() {
	InitGasman();
	InstIntFunc(IntComm);
	return 0;
}
/*
 * Heap and structures like 177.mesa
 * Author: Sen Ye
 * Date: 09/09/2013
 */
#include "aliascheck.h"

void begin(int *p, int *q) {
------- LABEL 1
}

void end(int *p, int *q) {
------- LABEL 2
}

void render(int *p, int *q) {
------- LABEL 3
}

struct api_table {
	void (*Begin)(int *, int *);
	void (*End)(int *, int *);
	void (*Render)(int *, int *);
};

struct context {
	struct api_table API;
	struct api_table Exec;
};

struct mesa_context {
	struct context * ctx;
};

void init_exec_pointers(struct api_table * table) {
	table->Begin = begin;
	table->End = end;
	table->Render = render;
}

void init_api_function(struct context * ctx) {
	init_exec_pointers(&ctx->Exec);
}

struct context * create_context() {
	// Create heap objects here
	struct context * ctx = (struct context*)malloc(sizeof(struct context));
	init_api_function(ctx);
	// If field-sensitive, following statement would create another two heap
	// objects
	ctx->API = ctx->Exec;
	return ctx;
}

struct context * CC;

void change_context(struct context * ctx) {
	CC = ctx;
}

void make_current(struct mesa_context * ctx) {
	change_context(ctx->ctx);
}

void draw(int *p, int *q, int *r) {
	(*CC->API.Begin)(p, q);
	if (p)
		q = r;
	if (*CC->API.Render) {
		(*CC->API.Render)(q, r);
		(*CC->API.End)(p, r);
	}
	else
		(*CC->API.End)(q, p);
}

void delete_context(struct context * ctx) {
	free (ctx);
}

int main() {
	int x,y,z;
	struct mesa_context * mesa = (struct mesa_context*)malloc(sizeof(struct mesa_context));
	mesa->ctx = create_context();
	make_current(mesa);
	draw(&x, &y, &z);
	delete_context(mesa->ctx);
	free(mesa);
	return 0;
}
/*
 * Aliases resulted by heap model in 197.parser.
 * Author: Sen Ye
 * Date: 09/05/2014
 */
#include "aliascheck.h"
#include <stdlib.h>

typedef struct X_node_struct X_node;
struct X_node_struct {
    int* string;
    X_node *next;
};

typedef struct Word_struct Word;
struct Word_struct {
    int* string;
    X_node * x;
};

typedef struct clause_struct Clause;
struct clause_struct {
    Clause * next;
};

/* Only one heap object O is allocated by xalloc() and
 * it will used in build_clause() and special_string().
 */
void * xalloc(int size) {
	return (void *) malloc(1000);
}

Word sentence[250];

void build_clause() {
    Clause *c=NULL, *c1, *c2;

	c1 = (Clause*) xalloc(sizeof (Clause));
	while(c1 != NULL) {
		c2 = c1->next; /* c2 = pts(c1) */
		c1->next = c;  /* pts(c1) = c */
		c = c1;        /* c = c1 */
		c1 = c2;       /* c1 = c2 */
	}
------- LABEL 1
}

void special_string(int i) {
    X_node * e;
	/* The unique heap object O will points-to object of 
	   sentence's first field after following code. */
	sentence[i].x = (X_node *) xalloc(sizeof(X_node));
	for (e = sentence[i].x; e != NULL; e = e->next) {
	    e->string = sentence[i].string;
	}
}

int main() {
	build_clause();
	special_string(10);
	return 0;
}
/*
 * Aliases resulted by context-insensitive and heap model in 255.vortex.
 * Author: Sen Ye
 * Date: 12/05/2014
 */
#include <stdlib.h>
#include "aliascheck.h"

typedef void *AddrType;
typedef AddrType addrtype;

typedef struct Ory
{
	addrtype *ChunkAddr;
} OryType;

OryType *Theory = NULL;

typedef struct Rectangle
{
	void (*draw) (int* p, float* q);
} Rectangle;

void Rectangle_draw(int* p, float* q) {}
addrtype Void_ExtendCore(long* p){}

void CoreMoreCore(addrtype *Region)
{
	long AllocCore1 = 0;
	*Region = (addrtype)Void_ExtendCore(&AllocCore1);
}

void MemNewOry()
{
	addrtype *ChunkAddrPtr = NULL;
	addrtype ChunkBlk = (addrtype)calloc(1,sizeof(addrtype));
	
	CoreMoreCore((addrtype*)(&Theory));

	if ((Theory->ChunkAddr = (addrtype*)ChunkBlk) != NULL)
	{
		ChunkAddrPtr = Theory->ChunkAddr;
		*ChunkAddrPtr = (addrtype)ChunkAddrPtr;
	}
}

void MemGetAddr(unsigned Chunk, unsigned index, addrtype *Addr)
{
	*Addr = *(((addrtype*)((Theory->ChunkAddr[Chunk])))+index);
}

void Object_GetImage(addrtype *This)
{
	unsigned chunk, index;
	MemGetAddr(chunk, index, This);
}

void Rectangle_new0()
{
	Rectangle* Image = NULL;
	Object_GetImage((addrtype*)&Image);
	Image->draw = Rectangle_draw;
}

void PartLib_Create(int **PrimalObj)
{
	Object_GetImage((addrtype *)PrimalObj);
}

int* PartLib01 = NULL;

int main()
{
	PartLib_Create(&PartLib01);
------- LABEL 1
	return 0;
}
#include "aliascheck.h"
void bar(int***k, int***s){

	*k = *s; 

}

int main(){
	int *p1,*q1,*r1,*a1,*b1,*c1,q2,a2;
	int **p = &p1;
	int **q = &q1;
	q1 = &q2;
	bar(&p,&q);
------- LABEL 1
}
/*
 * Alias due to struct assignment
 * Author: Sen Ye
 * Date: 06/09/2013
 */
#include "aliascheck.h"

struct s{
	int *a;
	int b;
};

int main()
{
	struct s s1, s2;
	struct s * p1;
	int x, y;
	s1.a = &x;
	s1.b = y;
	s2 = s1;
------- LABEL 1
	return 0;
}
/*
 * Alias due to struct assignment
 * Author: Sen Ye
 * Date: 06/09/2013
 */
#include "aliascheck.h"

struct s{
	int *a;
	int *b;
};

int main()
{
	struct s s1, s2;
	struct s * p1;
	int x, y;
	s1.a = &x;
	s1.b = &y;
	s2 = s1;
	p1 = &s1;
------- LABEL 1
------- LABEL 2
	return 0;
}
/*
 * Struct assignment.
 * Author: Sen Ye
 * Date: 28/04/2014
 */
#include "aliascheck.h"

struct InnerArrayStruct {
	int* in1[10];
	int* in2[20];
	char in3;
};

struct MidArrayStruct {
	char mid1[10];
	struct InnerArrayStruct mid2[5];
};

struct ArrayStruct {
	char out2;
	struct MidArrayStruct out3;
	int* out4;
};

int main() {
	struct ArrayStruct* p;
	struct ArrayStruct s1, s2;
	int x, y;

	s1.out4 = &x;
	p = &s1;
	p->out3.mid2[3].in1[3] = &y;

	s2 = s1;

------- LABEL 1
------- LABEL 2
------- LABEL 3
	
	return 0;
}
