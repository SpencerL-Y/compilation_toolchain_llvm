/*
 * Struct with array of structs.
 * Author: Sen Ye
 * Date: 28/04/2014
 */
#include "aliascheck.h"

struct InnerArrayStruct {
	int f1[100];
};

struct ArrayStruct {
	int f1;
	char f2;
	struct InnerArrayStruct f3;
	int f4;
};

int main() {
	struct ArrayStruct* p;
	struct ArrayStruct s;
	int* q;

	p = &s;
	q = &s.f3.f1[40];
------- LABEL 1
------- LABEL 2
------- LABEL 3
	
	return 0;
}
