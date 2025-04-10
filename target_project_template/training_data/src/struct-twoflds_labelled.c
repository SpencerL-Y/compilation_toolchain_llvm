/*
 * Struct with multiple fields.
 * Author: Sen Ye
 * Date: 28/04/2014
 */
#include "aliascheck.h"

struct IntChar {
	int f1;
	char f2;
};

struct CharInt {
	char f1;
	int f2;
};

int main() {
	struct IntChar* pint1, *pint2;
	struct IntChar s;
	pint1 = &s;
	pint2 = &s;
------- LABEL 1
------- LABEL 2
------- LABEL 3
	
	struct CharInt* qint1, *qint2;
	struct CharInt t;
	qint1 = &t;
	qint2 = &t;
------- LABEL 4
------- LABEL 5
------- LABEL 6

	return 0;
}
