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
