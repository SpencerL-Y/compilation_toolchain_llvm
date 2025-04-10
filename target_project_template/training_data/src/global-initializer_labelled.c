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
