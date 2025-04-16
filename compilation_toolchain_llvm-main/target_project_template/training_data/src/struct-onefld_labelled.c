/*
 * Struct with one field.
 * Author: Sen Ye
 * Date: 28/04/2014
 */
#include "aliascheck.h"

struct IntStruct {
	int f1;
};

struct CharStruct {
	char f1;
};

int main() {
	struct IntStruct* pint1, *pint2;
	struct IntStruct s;
	pint1 = &s;
	pint2 = &s;
------- LABEL 1
------- LABEL 2
	
	struct CharStruct* qint1, *qint2;
	struct CharStruct t;
	qint1 = &t;
	qint2 = &t;
------- LABEL 3
------- LABEL 4

	return 0;
}
