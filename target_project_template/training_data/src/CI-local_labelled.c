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
