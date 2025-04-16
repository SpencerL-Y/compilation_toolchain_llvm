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
