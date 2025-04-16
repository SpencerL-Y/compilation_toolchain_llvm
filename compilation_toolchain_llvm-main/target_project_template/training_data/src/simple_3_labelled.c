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
