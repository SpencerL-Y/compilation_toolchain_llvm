/*
 * Struct with array of structs.
 * Author: Sen Ye
 * Date: 28/04/2014
 */
#include "aliascheck.h"

struct InnerArrayStruct {
	int in1[10];
	char in2;
	double in3;
};

struct MidArrayStruct {
	char mid1;
	struct InnerArrayStruct mid2[5];
	double mid3[20];
};

struct ArrayStruct {
	int out1;
	char out2;
	struct MidArrayStruct out3;
	int out4;
};

int main() {
	struct ArrayStruct* p;
	struct ArrayStruct s;

	p = &s;

------- LABEL 1

	// array index out of bound
------- LABEL 2
------- LABEL 3
------- LABEL 4
------- LABEL 5
	
	return 0;
}
