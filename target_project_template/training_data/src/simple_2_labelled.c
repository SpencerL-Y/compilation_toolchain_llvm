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
